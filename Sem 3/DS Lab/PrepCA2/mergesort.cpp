// Merge Sort

#include <iostream>
#include <cstdlib>
using namespace std;

void Merge(int arr[], int temp[], int left, int mid, int right)
{
    int size, left_end, temp_pos, i;
    temp_pos = left;
    left_end = mid - 1;
    size = right - left + 1;
    while ((left <= left_end) && (mid <= right))
    {
        if (arr[left] <= arr[mid])
        {
            temp[temp_pos++] = arr[left++];
        }
        else
        {
            temp[temp_pos++] = arr[mid++];
        }
    }
    while (left <= left_end)
    {
        temp[temp_pos++] = arr[left++];
    }
    while (mid <= right)
    {
        temp[temp_pos++] = arr[mid++];
    }
    for (i = 0; i < size; i++)
    {
        arr[i] = temp[i];
    }
}

void MergeSort(int arr[], int temp[], int left, int right)
{
    if (left < right)
    {
        int mid = (left + right) / 2;
        MergeSort(arr, temp, left, mid);
        MergeSort(arr, temp, mid + 1, right);
        Merge(arr, temp, left, mid + 1, right);
    }
}

int main(int argc, char const *argv[])
{
    int arr[5] = {5, 1, 4, 2, 3};
    int temp[5];
    MergeSort(arr, temp, 0, 4);
    cout << "\nArray : ";
    for (int i = 0; i < 5; i++)
    {
        cout << arr[i] << " ";
    }
    return 0;
}
