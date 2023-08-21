// Shell Sort

#include <iostream>

using namespace std;

void swap(int arr[], int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

void shellsort(int arr[])
{
    int i, j, h, val;
    for (h = 5 / 2; h > 0; h /= 2)
    {
        for (i = h; i < 5; i++)
        {
            val = arr[i];
            j = i;
            while (val < arr[j - h] && j >= h)
            {
                arr[j] = arr[j - h];
                j -= h;
            }
            arr[j] = val;
        }
    }
}
int main(int argc, char const *argv[])
{
    int arr[5] = {5, 4, 3, 2, 1};
    shellsort(arr);
    cout << "\n\nArray : ";
    for (auto &a : arr)
    {
        cout << a << " ";
    }
    return 0;
}
