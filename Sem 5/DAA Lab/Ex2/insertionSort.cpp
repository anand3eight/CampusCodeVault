//Insertion Sort

#include<iostream>
#include<cstdlib>
using namespace std;

int insertionSort(int *arr, int n){
	int currentLen = 1, maxLen = 1, start = 0, currentStart = 0;
	for(int i = 1; i < n; i++){
		if(arr[i] < arr[i-1])	
			currentLen++;
		else{
			if(maxLen < currentLen){
				maxLen = currentLen;
				start = currentStart;
			}
			currentStart = i;
			currentLen = 1;
		}
	}
	if(maxLen < currentLen)
		maxLen = currentLen;
	int i, j;
	for(i = start + 1; i < start + maxLen; i++){
		j = i;
		while(j > 0 && arr[j] < arr[j-1]){
			swap(arr[j-1], arr[j]);
			j--;
		}
	}
	return maxLen;
}


int main(){
	int n;
	cout << "Enter n : ";
	cin >> n;
	int *arr = (int*)malloc(sizeof(int) * n);
	for(int i = 0; i < n; i++)
		cin >> arr[i];
	int sortedLen = insertionSort(arr, n);;
	cout << sortedLen << endl;
	for(int i = 0; i < n; i++)
		cout << arr[i] << " ";
	return 0;
	
}