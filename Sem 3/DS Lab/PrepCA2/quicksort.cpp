// Quick Sort Program

#include <iostream>
using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}
int partition(int arr[], int low, int high)
{
    int pivot_elmt = arr[high];
    int i = low - 1, j = low;
    while (j < high)
    {
        if (arr[j] < pivot_elmt)
        {
            swap(arr, ++i, j);
        }
        j++;
    }
    swap(arr, i + 1, high);
    return i + 1;
}
void quicksort(int arr[], int low, int high)
{
    if (low < high)
    {
        int pivot = partition(arr, low, high);
        quicksort(arr, low, pivot - 1);
        quicksort(arr, pivot + 1, high);
    }
}

int main(int argc, char const *argv[])
{
    int arr[5] = {5, 1, 2, 4, 3};
    quicksort(arr, 0, 4);
    cout << "\nArray : ";
    for (auto &a : arr)
    {
        cout << a << " ";
    }
    return 0;
}
