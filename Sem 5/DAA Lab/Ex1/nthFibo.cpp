//Last Digit of Nth Fibonacci Number

#include<iostream>
#include<cstdlib>
using namespace std;

int main(){
	int a = 0, b = 1, c, n;
	cout << "Enter n : ";
	cin >> n;
	cout << "Answer : ";
	if(n == 1)
		cout << 0;
	else if(n == 2)
		cout << 1;
	for(int i = 3; i < n+1; i++){
		c = a + b;
		a = b%10;
		b = c%10;
	}
	cout << c%10;
	return 0;
}
