// Radix Sort

#include <iostream>
using namespace std;

int getMaxArray(int arr[], int size)
{
      int max = arr[0];
      for (int i = 1; i < size; i++)
      {
            if (max < arr[i])
                  max = arr[i];
      }
      return max;
}

void countingSort(int arr[], int size, int exp)
{
      int countarr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
      for (int i = 0; i < size; i++)
      {
            countarr[(arr[i] / exp) % 10]++;
      }
      for (int i = 1; i < 10; i++)
      {
            countarr[i] += countarr[i - 1];
      }
      int orderedarr[size];
      for (int i = size - 1; i >= 0; i--)
      {
            orderedarr[--countarr[(arr[i] / exp) % 10]] = arr[i];
      }
      for (int i = 0; i < size; i++)
      {
            arr[i] = orderedarr[i];
      }
}

void radixSort(int arr[], int size)
{
      int m = getMaxArray(arr, size);
      for (int exp = 1; m / exp > 0; exp *= 10)
      {
            countingSort(arr, size, exp);
      }
}
int main(int argc, char const *argv[])
{
      int arr[] = {26, 1, 789, 23, 729};
      int len = sizeof(arr) / sizeof(arr[0]);
      radixSort(arr, len);
      cout << "\nSorted Array : ";
      for (auto &a : arr)
      {
            cout << a << " ";
      }
      return 0;
}
