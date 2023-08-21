//Flight Connectivity Check

#include<iostream>
#include<cstdlib>
#include<stack>
using namespace std;

void DFS(vector<int> *G, int s, vector<int> &vis){
    vis[s] = 1;
    for(auto i : G[s]){
        if(!vis[i])
            DFS(G, i, vis);
    }
}

bool visCheck(vector<int> &vis){
    for(int i = 1; i < vis.size(); i++){
        if(!vis[i])
            return false;
    }
    return true;
}
bool SCC(vector<int> *G, int m){
    vector<int> vis(m, 0);
    DFS(G, 1, vis);
    if(!visCheck(vis))  return false;
    vector<int> GT[m];
    for(int i = 1; i < m; i++){
        for(auto j : G[i])
            GT[j].push_back(i);
    }
    vector<int> vis2(m, 0);
    DFS(GT, 1, vis2);
    if (!visCheck(vis2))
        return false;
    return true;
}

int main(){
    int m, n;
    cin >> m >> n;
    vector<int> G[m+1];
    for(int i = 0; i < n; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
    }
    int ans = SCC(G, m+1);
    if(ans)
        cout << "YES";
    else 
        cout << "NO";
    return 0;
}