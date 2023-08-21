//If cycle exists in a Graph

#include<iostream>
#include<cstdlib>
#include<vector>
using namespace std;

bool isCyclicGraph(vector<int> *adjList, int *visited, int head){
	visited[head] = 1;
	for(auto i : adjList[head]){
		if(visited[i] == 0)
			
			isCyclicGraph(adjList, visited, i);
		else
			return true;
	}
	return false;
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
	if(isCyclicGraph(adjList, visited, 0))
		cout << "True";
	else 
		cout << "False";
}