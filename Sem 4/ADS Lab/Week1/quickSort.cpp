//Binary Search

#include<iostream>
using namespace std;

int partition(int arr[], int low, int high){
	int i = low - 1, j = low, pivot = arr[high], temp;
	for(; j < high; j++){
		if(pivot > arr[j]){
			temp = arr[++i];
			arr[i] = arr[j];
			arr[j] = temp;
		}
	}
	temp = arr[++i];
	arr[i] = pivot;
	arr[high] = temp;
	return i;
}

void quickSort(int arr[], int left, int right){
	if(left < right){
		int p = partition(arr, left, right);
		quickSort(arr, left, p-1);
		quickSort(arr, p+1, right);
	}
}

int main(){
	int val, len;
	cout << "Enter Array Length : ";
	cin >> len;
	int arr[len];
	cout << "Enter Array Elements : ";
	for(int i = 0; i < len; i++){
		cin >> arr[i];
	}
	quickSort(arr, 0, len-1);
	cout << "Sorted Array : "; 
	for(int i = 0; i < len; i++){
		cout << arr[i] << " ";
	}
}
