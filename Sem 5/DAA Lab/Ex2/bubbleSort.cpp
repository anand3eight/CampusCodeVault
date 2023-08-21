//Bubble Sort TV Viewing Times

#include<iostream>
#include<cstdlib>
using namespace std;

struct Details{
	string channelName;
	int viewTime;
};
typedef struct Details D;

void bubbleSort(D *arr, int n){
	for(int i = 0; i < n; i++){
		for(int j = 0; j < n-i-1; j++){
			if(arr[j].viewTime > arr[j+1].viewTime)
				swap(arr[j], arr[j+1]);
		}
	}
}
int main(){
	int n;
	cout << "Enter n : ";
	cin >> n;
	cout << "Enter Channels and Viewing Time : " << endl;
	D arr[n];
	for(int i = 0; i < n; i++)
		cin >> arr[i].channelName >> arr[i].viewTime;	
	bubbleSort(arr, n);
	for(int i = 0; i < n; i++){
		cout << arr[i].channelName;
		if(i < n-1)
			cout << ", ";
	}
	return 0;
}