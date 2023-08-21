// counting Sort

#include <iostream>
using namespace std;

void countingSort(int arr[], int size)
{
    int countarr[] = {0, 0, 0, 0, 0, 0, 0, 0, 0, 0};
    for (int i = 0; i < size; i++)
    {
        countarr[arr[i]]++;
    }
    for (int i = 1; i < 9; i++)
    {
        countarr[i] += countarr[i - 1];
    }
    int orderedarr[size];
    for (int i = 0; i < size; i++)
    {
        orderedarr[--countarr[arr[i]]] = arr[i];
    }
    for (int i = 0; i < size; i++)
    {
        arr[i] = orderedarr[i];
    }
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 5, 2, 8, 6, 7};
    int len = sizeof(arr) / sizeof(arr[0]);
    countingSort(arr, len);
    cout << "Sorted Array : ";
    for (auto &a : arr)
    {
        cout << a << " ";
    }
    return 0;
}
