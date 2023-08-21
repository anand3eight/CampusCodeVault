//Merge Sort

#include<iostream>
#include<cstdlib>
using namespace std;

void merge(int *arr, int len, int k, int l, int m, int n){
    int *temp = (int*)malloc(sizeof(int) * len);
    int i = k, j = m, a = k;
    while(i <= l && j <= n){
        if(arr[i] < arr[j])
        temp[a++] = arr[i++];
        else
        temp[a++] = arr[j++]; 
    }
    while(i <= l)
        temp[a++] = arr[i++];
    while(j <= n)
        temp[a++] = arr[j++];
    for(int i = k; i <= n; i++)
        arr[i] = temp[i];
}

void split(int *arr, int st, int end, int len){
    if(st < end){
        int mid = st + (end-st)/2;
        split(arr, st, mid, len);
        split(arr, mid+1, end, len);
        merge(arr, len, st, mid, mid+1, end);
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
    split(arr, 0, len-1, len);
    cout << "Sorted Array : ";
    for(int i = 0; i < len; i++)   
        cout << arr[i] << " ";
}
