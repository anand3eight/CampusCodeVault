//Dikstra's Algorithm for weighted, undirected Graphs

#include<bits/stdc++.h>
using namespace std;

void DijkstraSolver(vector<pair<int, int> > *G, int v, int e){
	priority_queue<pair<int, int>, vector<pair<int, int> >, greater<pair<int, int> > > pq;
	vector<int> dist(v+1, 1e9);
	dist[1] = 0;
	pq.push(make_pair(0, 1));
	while(!pq.empty()){
		int prev = pq.top().second;
		pq.pop();
		vector<pair<int, int> > :: iterator it;
		for(it = G[prev].begin(); it != G[prev].end(); it++){
			int next = it->first;
			int nextDist = it->second; 
			if(dist[next] > dist[prev] + nextDist){
				dist[next] = dist[prev] + nextDist;
				pq.push(make_pair(dist[next], next));
			}
		}
	}
	cout << "Distances : ";
	for(int i = 1; i < v+1; i++){
		cout << dist[i] << " ";
	}
}
int main(){
	int v, e;
	cin >> v >> e;
	vector<pair<int, int> > G[v+1];
	for(int i = 0; i < e; i++){
		int a, b, c;
		cin >> a >> b >> c;
		G[a].push_back(make_pair(b, c));
		G[b].push_back(make_pair(a, c));
	}
	DijkstraSolver(G, v, e);
	return 0;
}
