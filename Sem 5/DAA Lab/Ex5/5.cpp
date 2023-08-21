//Check Graph Connections

#include<iostream>
#include<cstdlib>
#include<stack>
#include<vector>
using namespace std;
int ans = 0;
void dfs(vector<int> *Graph, int s, int d, vector<int>& vis){
	vis[s] = 1;
	for(int j = 0; j < Graph[s].size(); j++)
	{
		int a = Graph[s][j];
		if(a == d){
			ans = 1;
			return;
		}
		if(!vis[a])
			dfs(Graph, a, d, vis);	
	}
} 

int main(){
	int v, e, a, b;
	cin >> v >> e;
	vector<int> graph[v+1];
	for(int i = 0; i < e; i++){
		cin >> a >> b;
		graph[a].push_back(b);
		graph[b].push_back(a);
	}
	vector<int> vis(v+1, 0);
	dfs(graph, 1, v, vis);
	if(ans)
		cout << "Possible";
	else
		cout << "Impossible";
	return 0;
}
