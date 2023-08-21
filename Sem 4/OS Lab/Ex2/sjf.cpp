//Shortest Job First

#include<iostream>
#include<cstdlib>
#include<queue>
#include<iomanip>
using namespace std;
typedef struct Process Process;
struct Process
{
	char ID[10];
	int at, bt;
};

struct compareHeight{
	bool operator()(Process const& n1, Process const& n2){
		if(n1.at == n2.at)
			return n1.bt < n2.bt;
		return (n1.at > n2.at);
	}
};

int main(){
	Process p;
	priority_queue<Process, vector<Process>, compareHeight> pq;
	int n, st, wt = 0, twt = 0, tat = 0, ttat = 0;
	cout << "Enter No. of Processes : ";
	cin >> n;
	cout << "Enter Details : " << endl;
	for(int i = 0; i < n; i++){
		cout << "ID : ";
		cin >> p.ID;
		cout << "AT : ";
		cin >> p.at;
		cout << "BT : ";
		cin >> p.bt;
		pq.push(p);
	}
	cout << "Table : " << endl;
	cout << setw(10) << "ID" << setw(6) << "AT" << setw(6) << "BT" << setw(6) << "ST" << setw(6) << "WT" <<  setw(6) << "TAT" << setw(6) << "RT" << endl;  
	while(!pq.empty()){
		p = pq.top();
		if(p.at > st)
			cout << setw(10) << p.ID << setw(6) << p.at << setw(6) << p.bt << setw(6) << st << setw(6) << 0 <<  setw(6) << (st - p.at) + p.bt << setw(6) << (st - p.at) + p.bt << endl;  
		else
			cout << setw(10) << p.ID << setw(6) << p.at << setw(6) << p.bt << setw(6) << st << setw(6) << st - p.at <<  setw(6) << (st - p.at) + p.bt << setw(6) << (st - p.at) + p.bt << endl;  
		st += p.bt;
		twt += (st - p.bt);
		ttat += (st - p.at) + p.bt;
		pq.pop();
	}
	cout << setw(42) << "Average WT :" << setw(8) << setprecision(2) << (float)twt/n << endl;
	cout << setw(42) << "Average TAT :" << setw(8) << setprecision(2) << (float)ttat/n << endl;
	return 0;
}
