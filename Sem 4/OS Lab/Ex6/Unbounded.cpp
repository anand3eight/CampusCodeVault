//Producer - Consumer Problem - Unbounded Buffer Problem
#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int full = 0;
vector <int> buffer;

void producer(){
	int val;
	cout << "Enter Data : ";
	cin >> val;
	buffer.push_back(val);
	full++;
}

void consumer(){
	int val;
	val = buffer.front();
	buffer.erase(buffer.begin()+0);
	cout << "Data : " << val << endl;
	full--;	
}

int main()
{
	int ch, chk = 1;
	while(chk == 1){
		cout << "1 : Producer \n2 : Consumer";
		cout << "\nEnter the Choice : ";
		cin >> ch;
		if(ch == 1)
				producer();
		else if(ch == 2){
			if(full != 0)
				consumer();
			else
				cout << "Buffer is Empty" << endl;
		}
		cout << endl << "To continue, Press 1 : ";
		cin >> chk;
	}
	return 0;
}
