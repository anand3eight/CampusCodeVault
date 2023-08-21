//Number of Reachable Nodes

#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

int maxConnected(vector<int> *adjList, int *visited, int head){
	visited[head] = 1;
	int count = 0;
	for(auto i : adjList[head]){
		if(visited[i] == 0)
			count += maxConnected(adjList, visited, i);
	}
	return count+1;
}
int main(){
	int v, e, j, k, head;
	cout << "Enter No. of Vertices and Edges : ";
	cin >> v >> e;
	vector<int> adjList[v];
	cout << "Enter Edges : " << endl;
	for(int i = 0; i < e; i++){
		cin >> j >> k;
		adjList[j].push_back(k);
		adjList[k].push_back(j);
	}
	int visited[v] = {0};
	cout << "Enter Head : ";
	cin >> head;
	cout << "Max Connected Nodes : " << maxConnected(adjList, visited, head);
}