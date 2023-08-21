//Shortest Remaining Time First


#include<iostream>
#include<cstdlib>
#include<iomanip>
using namespace std;

void findWaitingTime(int *prs, int n, int *bt, int *at, int *wt, int tq){
	int rembt[n], t = 0, shortest, min = INT_MAX, c = 0;
	bool done; //To check if any process is present in t
	for(int i = 0; i < n; i++){
		rembt[i] = bt[i];
	}	
	while(c != n){
		done = true;
		for(int i = 0; i < n; i++){
			if(at[i] <= t && (rembt[i] > 0 && min > at[i])){
				min = at[i];
				shortest = i;
				done = false;
				}
			}
			if(done == false){
				if(rembt[shortest] > tq){
					t += tq;
					rembt[shortest] -= tq;
				}
				else{
					t += rembt[shortest];
					rembt[shortest] = 0;
					wt[shortest] = t - bt[shortest] - at[shortest];
					min = INT_MAX;
					c++;
				}
			}
			else
				t++;
	}
}

void findTAT(int *prs, int n, int *bt, int *wt, int *tat){
	for(int i = 0; i < n; i++){
		tat[i] = bt[i] + wt[i];
	}
}

void findAvg(int *prs, int n, int *bt, int *at, int tq){
	int wt[n], tat[n], twt = 0, ttat = 0;
	findWaitingTime(prs, n, bt, at, wt, tq);
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
