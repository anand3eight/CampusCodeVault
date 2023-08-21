//Linear Search

#include<iostream>
 
using namespace std;
int linearSearch(int arr[], int len, int val){
	for(int i = 0; i < len; i++){
		if(arr[i] == val)
			return i;
	}
	return -1;
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
	cout << "Enter Search Element : ";
	cin >> val;
	int flag = linearSearch(arr, len, val);
	if(flag != -1)
		cout << "Index of "<< val << " is " << flag ;
	else
		cout << "Element Not Found"; 
	
}
