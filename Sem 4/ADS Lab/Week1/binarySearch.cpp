//Binary Search

#include<iostream>
using namespace std;

int binarySearch(int arr[], int left, int right, int val){
		if(left < right){
			int mid = (left + right)/2;
			if(arr[mid] == val)
				return mid;
			else if(arr[mid] < val)
				return binarySearch(arr, mid + 1, right, val);
			else if(arr[mid] > val)
				return binarySearch(arr, left, mid - 1, val);
			}
		else{
			return -1;
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
	cout << "Enter Search Element : ";
	cin >> val;
	int flag = binarySearch(arr, 0, len-1, val);
	if(flag != -1)
		cout << "Index of "<< val << " is " << flag ;
	else
		cout << "Element Not Found"; 
	
}
