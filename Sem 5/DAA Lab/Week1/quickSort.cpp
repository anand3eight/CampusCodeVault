//Quick Sort

#include<iostream>
#include<cstdlib>
using namespace std;

int partition(int *arr, int l, int h){
	int pivot = arr[h];
	int i = l;
	for(int j = l; j < h; j++){
		if(arr[j] < pivot)
			swap(arr[j] ,arr[i++]);
	}
	swap(arr[i], arr[h]);
	return i; 
}

void quickSort(int *arr, int st, int end){
	if(st <= end){
		int i = partition(arr, st, end);
		quickSort(arr, st, i-1);
		quickSort(arr, i+1, end);
		return;
	}
}

int main(){
	int len;
    cout << "Enter Array Length : ";
    cin >> len;
    int *arr = (int*)malloc(sizeof(int)* len);
    cout << "Enter Array : ";
    for(int i = 0; i < len; i++)
    	cin >> arr[i];
    quickSort(arr, 0, len-1);
    cout << "Sorted Array : ";
    for(int i = 0; i < len; i++)   
        cout << arr[i] << " ";
}


