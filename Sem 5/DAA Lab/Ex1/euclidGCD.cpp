//GCD Of Two Numbers

#include<iostream>
using namespace std;

int gcd(int a, int b){
	if(a < b)
		return (a == 0) ? b : gcd(b%a, a);
	else
		return (b == 0) ? a : gcd(a%b, b);
}

int main(){
	int a, b;
	cout << "Enter a and b : ";
	cin >> a >> b;
	cout << "GCD : " << gcd(a, b);
}