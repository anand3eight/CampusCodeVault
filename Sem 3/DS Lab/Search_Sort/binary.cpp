//Binary Search

#include<iostream>
using namespace std;

int binarySearch(int arr[], int low, int high, int val)
{
	if(low <= high)
	{
		int mid = low + (high - low)/2;
		if(val == arr[mid])
			return mid;
		else if (val < arr[mid])
			return binarySearch(arr, low, mid-1, val);
		else if(val > arr[mid])
			return binarySearch(arr, mid+1, high, val);
		else
			return -1;
	}
}

int main()
{
	int arr[150];
	for(int i = 0; i < 150; i++)
	{
		arr[i] = 5*i;
	}
	cout << "\nIndex : " << binarySearch(arr, 0, 150, 150);
	return 0;
}
