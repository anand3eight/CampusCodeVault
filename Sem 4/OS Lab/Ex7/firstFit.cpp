//Memory Allocation - Variable Partitions - First Fit

#include<iostream>
#include<cstdlib>
using namespace std;

typedef struct Holes H; 
struct Holes{
	int filled = 0;
	int spaceAvailable;
	int spaceOccupied = 0;
};

void firstFit(H *holes, int *Processes, int noOfHoles, int noOfProcesses){
	int flag;
	for(int i = 0; i < noOfProcesses; i++){
		flag = 0;
		for(int j = 1; j < noOfHoles; j++){
			if(holes[j].filled != 1 && holes[j].spaceAvailable >= Processes[i]){
				cout << "Process " << i+1 << " is allocated with Hole " << j+1 << endl;
				holes[j].spaceOccupied += Processes[i];
				holes[j].spaceAvailable -= Processes[i];
				if(holes[j].spaceAvailable == 0)
					holes[j].filled = 1;
				flag = 1;
				break;
			}
		}	
		if(flag == 0){
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
	firstFit(holes, processes, noOfHoles, noOfProcesses);

	return 0;
}
