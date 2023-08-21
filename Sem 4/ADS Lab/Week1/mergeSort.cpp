//Binary Search

#include<iostream>
using namespace std;

void merge(int arr[], int ls, int mid, int re){
	int le = mid, rs = mid + 1, size = re - ls + 1;
	int i = ls, j = rs, k = ls;
	int temp[size];
	while(i <= le && j <= re){
		if(arr[i] < arr[j]){
			temp[k] = arr[i];
			i++;
		}
		else{
			temp[k] = arr[j];
			j++;
		}
		k++;
	}
	
	while(i <= le){
		temp[k] = arr[i];
		k++;
		i++;
	}
	while(j <= re){
		temp[k] = arr[j];
		k++;
		j++;
	} 
	for(i = ls; i <= re; i++){
		arr[i] = temp[i];
	}
}

void mergeSort(int arr[], int left, int right){
	if(left < right){
		int mid = (left + right)/2;
		mergeSort(arr, left, mid);
		mergeSort(arr, mid+1, right);
		merge(arr, left, mid, right);
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
	mergeSort(arr, 0, len-1);
	cout << "Sorted Array : "; 
	for(int i = 0; i < len; i++){
		cout << arr[i] << " ";
	}
}
