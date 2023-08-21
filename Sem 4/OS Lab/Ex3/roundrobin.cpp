//Round Robin Algorithm

#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

void findWaitingTime(int *prs, int n, int *bt, int *at, int tq, int *wt){
	int rembt[n], t = 0;
	for(int i = 0; i < n; i++){
		rembt[i] = bt[i];
	}	
	cout << "Order : ";
	while(1){
		bool done = true; //Assume all Processes are completed
		for(int i = 0; i < n; i++){
			if(at[i] > t){
				done = false;
				continue;
			}
			if(rembt[i] > 0){ 
				done = false;
				if(rembt[i] > tq){ //If Remaining burst Time is greater than Time Quantum
					t += tq;
					rembt[i] -= tq;
				}
				else{ //Remaining Burst Time is less than Time Quantum
					t += rembt[i];
					rembt[i] = 0;
					wt[i] = t - bt[i] - at[i];
					cout << "p" << (i+1) << " ";
				}
			}
		}
		if(done == true){
			cout << endl;
			break;
	}
	}
}

void findTAT(int *prs, int n, int *bt, int *wt, int *tat){ //Calculate TAT
	for(int i = 0; i < n; i++){
		tat[i] = bt[i] + wt[i];
	}
}

void findAvg(int *prs, int n, int *bt, int *at, int tq){ //Call functions and Calculate Average
	int wt[n], tat[n], twt = 0, ttat = 0;
	findWaitingTime(prs, n, bt, at, tq, wt);
	findTAT(prs, n, bt, wt, tat);
	cout << setw(6) << "ID" << setw(6) << "BT" << setw(6) << "WT" << setw(6) << "TAT" << endl; 
	for(int i = 0; i < n; i++){
		ttat += tat[i];
		twt += wt[i];
		cout << setw(6) << prs[i] << setw(6) << bt[i] << setw(6) << wt[i] << setw(6) << tat[i] << endl;
		
	}
	cout << setw(30) << "Average Waiting Time : " << setw(6) << setprecision(5) << (float)twt/n << endl;
	cout << setw(30) << "Average Turn Around Time : " << setw(6) << setprecision(5) << (float)ttat/n << endl;
}

int main(){
	int n, tq;
	cout << "Enter Number of Processes : ";
	cin >> n;
	cout << "Enter Time Quantum : ";
	cin >> tq;
	int prs[n], bt[n], at[n];
	cout << "Enter Details : " << endl;
	for(int i = 0; i < n; i++){
		prs[i] = i+1;
		cout << "Enter AT : ";
		cin >> at[i];
		cout << "Enter BT : ";
		cin >> bt[i];
		cout << endl;
	}
	findAvg(prs, n, bt, at, tq);
}
