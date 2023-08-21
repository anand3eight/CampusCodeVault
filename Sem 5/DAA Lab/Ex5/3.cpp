//Precedence Graph Traveral

#include<iostream>
#include<cstdlib>
#include<stack>
#include<vector>
using namespace std;

void dfs(int i, vector<int> *Graph, stack<int>& ans, vector<int>& vis){
	vis[i] = 1;
	for(int j = 0; j < Graph[i].size(); j++)
	{
		int a = Graph[i][j];
		if(!vis[a])
			dfs(a, Graph, ans, vis);
	}
	ans.push(i);
} 
void precedenceGraph(vector<int> *Graph, int v){
	vector<int> vis(v+1, 0);
	stack<int> ans; 
	for(int i = 1; i < v+1; i++){
		if(!vis[i]){
			dfs(i, Graph, ans, vis);
		}
	}	
	while(!ans.empty()){
		int t = ans.top();
		cout << t << " ";
		ans.pop();
	}
}

int main(){
	int v, e, a, b;
	cin >> v >> e;
	vector<int> graph[v+1];
	for(int i = 0; i < e; i++){
		cin >> a >> b;
		graph[a].push_back(b);
	}
	precedenceGraph(graph, v);
	return 0;
}
