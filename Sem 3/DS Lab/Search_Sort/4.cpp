//Selection Sort

#include<iostream>
using namespace std;

void selectionSort(int arr[], int len)
{
	int temp;
	for(int i = 0; i < len; i++)
	{
		for(int j = i+1; j < len; j++)
		{
			if(arr[i] > arr[j])
			{
				temp = arr[i];
				arr[i] = arr[j];
				arr[j] = temp;
			}
		}
	}
}

int main()
{
	int arr[] = {4, 1, 2, 5, 3};
	selectionSort(arr, 5);
	cout << "Array : ";
	for(int i = 0; i < 5; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}
