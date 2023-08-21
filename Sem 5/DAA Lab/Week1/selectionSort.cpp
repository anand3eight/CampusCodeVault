//Selection Sort

#include<iostream>
#include<cstdlib>
using namespace std;

void selectionSort(int *arr, int len){
	for(int i = 0; i < len-1; i++){
		for(int j = i+1; j < len; j++){
			if(arr[i] > arr[j])
				swap(arr[i], arr[j]);
		}
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
    selectionSort(arr, len);
    cout << "Sorted Array : ";
    for(int i = 0; i < len; i++)   
        cout << arr[i] << " ";
}
