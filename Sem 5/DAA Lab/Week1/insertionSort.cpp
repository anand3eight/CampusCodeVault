//Insertion Sort

#include<iostream>
#include<cstdlib>
using namespace std;

void insertionSort(int *arr, int len){
	for(int i = 0; i < len-1; i++){
		int j = i;
		while(j > -1 && arr[j+1] < arr[j]){
			swap(arr[j+1], arr[j]);
			j--;
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
    insertionSort(arr, len);
    cout << "Sorted Array : ";
    for(int i = 0; i < len; i++)   
        cout << arr[i] << " ";
}
