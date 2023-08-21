//String Matching
// Z- Algorithm

#include<iostream>
#include<cstdlib>
using namespace std;

void getArr(string concat, int *z)
{
	z[0] = -1;
	for(int i = 1; i < concat.length(); i++){
		int c = 0, ind = 0;
		for(int j = i; j < concat.length(); j++){
			if(concat[j] == concat[ind]){
				ind++;
				c++;
			}
			else
				break;
		}
		z[i] = c;
	}
}

int search(int *z, int m, int len){
	for(int i = 0; i < len; i++){
		if(z[i] == m)
			return 1;		
	}
	return 0;
}

int main(){
	string text, pattern;
	cout << "Enter Text and Pattern : ";
	cin >> text >> pattern;
	string concat = pattern + "$" + text;
	int z[concat.length()];
	getArr(concat, z);
	int ans = search(z, pattern.length(), concat.length());
	if(ans)
		cout << "Pattern Found";
	else
		cout << "Pattern Not Found";
	return 0;
	
}
