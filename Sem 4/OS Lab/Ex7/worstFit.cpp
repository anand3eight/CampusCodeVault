//Memory Allocation - Variable Partitions - Worst Fit

#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Holes H; 
struct Holes{
	int filled = 0;
	int spaceAvailable;
	int spaceOccupied = 0;
};

void worstfit(H *holes, int *Processes, int noOfHoles, int noOfProcesses){
	int max, flag;
	for(int i = 0; i < noOfProcesses; i++){
		flag = 0;
		max = -1;
		for(int j = 1; j < noOfHoles; j++){
			if(holes[j].filled != 1 && holes[j].spaceAvailable >= Processes[i]){
				if(flag == 0){
					max = j;
					flag = 1;
				}
				else if(holes[j].spaceAvailable > holes[max].spaceAvailable)
					max = j;
			}
		}	
		if(flag == 1){
		cout << "Process " << i+1 << " is allocated with Hole " << max+1 << endl;
				holes[max].spaceOccupied += Processes[i];
				holes[max].spaceAvailable -= Processes[i];
				if(holes[max].spaceAvailable == 0)
					holes[max].filled = 1;
		}
		else if(flag == 0){
			cout << "Process " << i+1 << " cannot be allocated with a Hole" << endl;
		}
	}
}

int main(){
	int noOfHoles;
	cout << "Enter No. of Holes : ";
	cin >> noOfHoles;
	H holes[noOfHoles];
	
	cout << "Enter Size of Holes " << endl;
	for(int i = 0; i < noOfHoles; i++){
		cout << "Hole " << i+1 << " : ";
		cin >> holes[i].spaceAvailable;
	}
	
	int noOfProcesses;
	cout << "Enter No of Processes : ";
	cin >> noOfProcesses;
	int processes[noOfProcesses];
	cout << "Enter Space Required for Each Processes : " << endl;
	for(int i = 0; i < noOfProcesses; i++){
		cout << "Process " << i+1 << " : ";
		cin >> processes[i];
	}
	cout << endl;
	worstfit(holes, processes, noOfHoles, noOfProcesses);

	return 0;
}
