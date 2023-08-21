//LevelOrder Traversal Sort

#include<iostream>
#include<math.h>
using namespace std;

void levelSort(int arr[], int len)
{
	int temp;
	for(int i = 0; i < len; i = pow(2, i+1) - 1)
	{
		for(int j = i; j < pow(2, i+1) - 1 && j < len; j++)
		{
			for(int k = j+1; k < pow(2, i+1) - 1 && k < len; k++)
			{
				if(arr[j] > arr[k])
				{
					temp = arr[j];
					arr[j] = arr[k];
					arr[k] = temp;	
				}
			}
		}
	}
}

int main()
{
	int arr[] = {1, 3, 2, 7, 6, 5, 4};
	levelSort(arr, 7);
	cout << "\nArray : ";
	for(int i = 0; i < 7; i++)
	{
		cout << arr[i] << " ";
	}
	return 0;
}

