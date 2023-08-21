// Insertion Sort

#include <iostream>
using namespace std;

void insertionsort(int arr[])
{
    int val, i, j;
    for (i = 1; i < 5; i++)
    {
        val = arr[i];
        j = i;
        while (val < arr[j - 1] && j > 0)
        {
            arr[j] = arr[j - 1];
            j--;
        }
        arr[j] = val;
    }
}
int main(int argc, char const *argv[])
{
    int arr[5] = {5, 4, 3, 2, 1};
    insertionsort(arr);
    cout << "\nArray : ";
    for (auto &a : arr)
    {
        cout << a << " ";
    }
    return 0;
}
