//Interval Scheduling

#include<bits\stdc++.h>
using namespace std;

void activityScheduling(vector<pair<int, int> >jobs, int n){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	vector<pair<int, int> > ans;
	for(int i = 0; i < n; i++)
		pq.push(jobs[i]);
	int st = pq.top().second;
	int end = pq.top().first;
	pq.pop();
	ans.push_back(make_pair(st, end));
	while(!pq.empty()){
		int s = pq.top().second;
		int f = pq.top().first;
		pq.pop();
		if(s >= end){
			st = s;
			end = f;
			ans.push_back(make_pair(st, end));
		}
	}
	vector<pair<int, int> > :: iterator itr;
	for(itr = ans.begin(); itr != ans.end(); itr++){
		cout << "(" << itr->first << ", " << itr->second << ")" << endl;
	}
}

int main(){
	cout << "Enter n : ";
	int n;
	cin >> n;
	vector<pair<int, int> > jobs;
	cout << "Enter Jobs : ";
	for(int i = 0; i < n; i++){
		int s, f;
		cin >> s >> f;
		jobs.push_back(make_pair(f, s));	
	}
	activityScheduling(jobs, n);
	return 0;
}
