//MergeSort

#include<iostream>
#include<cstdlib>
using namespace std;

void merge(int *arr, int low, int mid, int high, int len){
	int i = low, j = mid, k = mid+1, l = high;
	int temp[len];
	int a = i;
	while(i <= j && k <= l){
		if(arr[i] < arr[k])
			temp[a++] = arr[i++];
		else
			temp[a++] = arr[k++];
	}	
	while(i <= j)
		temp[a++] = arr[i++];
	while(k <= l)
		temp[a++] = arr[k++];
	for(int a = low; a <= high; a++){
		arr[a] = temp[a];
	}
}

void mergeSort(int *arr, int low, int high, int len){
	if(low < high){
		int mid = low + (high-low)/2;
		mergeSort(arr, low, mid, len);
		mergeSort(arr, mid+1, high, len);
		merge(arr, low, mid, high, len);
	}
}

int main(){
	int n;
	cout << "Enter n : ";
	cin >> n;
	int *arr = (int*)malloc(sizeof(int) * n);
	cout << "Enter Elements : ";
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	mergeSort(arr, 0, n-1, n);
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
}