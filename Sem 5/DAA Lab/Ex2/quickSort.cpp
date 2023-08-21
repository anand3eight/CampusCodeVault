//Quicksort

#include<iostream>
#include<cstdlib>
using namespace std;

int partition(int *arr, int low, int high){
	int i = -1, j = 0, pivot = arr[high];
	for(j = 0; j < high; j++){
		if(arr[j] < pivot)
			swap(arr[++i], arr[j]);
	}
	swap(arr[++i], arr[high]);
	return i;
}

void quickSort(int *arr, int low, int high){
	if(low < high){
		int mid = partition(arr, low, high);
		quickSort(arr, low, mid-1);
		quickSort(arr, mid+1, high);
	}
}

int main(){
	int n;
	cout << "Enter n : ";
	cin >> n;
	int *arr = (int*)malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	quickSort(arr, 0, n-1);
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
}