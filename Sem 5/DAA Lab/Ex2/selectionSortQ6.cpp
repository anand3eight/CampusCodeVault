//Selection Sort

#include<iostream>
#include<cstdlib>
using namespace std;

struct Details{
	string Date;
	int tokenNo, order;
};
typedef struct Details D;

void selectionSort(D *arr, int n){
	for(int i = 0; i < n-1; i++){
		for(int j = i+1; j < n; j++){
			if(arr[j].Date < arr[i].Date || (arr[i].Date == arr[j].Date && arr[j].tokenNo < arr[i].tokenNo))
				swap(arr[i], arr[j]);
		}
	}	
}

int main(){
	int n;
	cout << "Enter n : ";
	cin >> n;
	cout << "Enter Date and Token No : " << endl;
	D arr[n];
	for(int i = 0; i < n; i++){
		cin >> arr[i].Date >> arr[i].tokenNo;	
		arr[i].tokenNo = i+1;
	}
	selectionSort(arr, n);
	for(int i = 0; i < n; i++)
		cout << arr[i].tokenNo << " ";
	return 0;
}