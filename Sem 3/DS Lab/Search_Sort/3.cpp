// Minimum Number of Swaps

#include <iostream>
using namespace std;

void arraySort(int arr[], int size)
{
    int temp;
    for (int i = 0; i < size; i++)
    {
        for (int j = i + 1; j < size; j++)
        {
            if (arr[i] > arr[j])
            {
                temp = arr[i];
                arr[i] = arr[j];
                arr[j] = temp;
            }
        }
    }
}

void copy(int arr1[], int arr2[], int size)
{
    for (int i = 0; i < size; i++)
    {
        arr2[i] = arr1[i];
    }
}

int indexOf(int arr[], int val, int size)
{
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == val)
        {
            return i;
        }
    }
    return -1;
}
int swapcheck(int sortedarr[], int arr[], int size)
{
    int j, swaps = 0;
    for (int i = 0; i < size; i++)
    {
        if (sortedarr[i] == arr[i])
            continue;
        else
        {
            j = indexOf(sortedarr, arr[i], size);
            if (arr[j] == sortedarr[i])
            {
                swaps++;
            }
        }
    }
    return swaps / 2;
}
int main(int argc, char const *argv[])
{
    int arr[] = {1, 5, 4, 3, 2};
    int len = sizeof(arr) / sizeof(arr[0]);
    int temp[len];
    copy(arr, temp, len);
    arraySort(arr, len);
    cout << "Min Number of Swaps : " << swapcheck(arr, temp, len);
    return 0;
}
