//Blocking Roads to stop Criminals

#include<iostream>
using namespace std;

void DFS(vector<int> *G, int a, int b, int c, vector<int> &vis){
    if(a == c)
        return ;
    vis[a] = 1;
    for(auto i : G[a]){
        if(!vis[i])
            DFS(G, i, b, c, vis);
    }
}

int main(){
    int n, e;
    cin >> n >> e;
    vector<int> G[n+1];
    for(int i = 0; i < e; i++){
        int a, b;
        cin >> a >> b;
        G[a].push_back(b);
        G[b].push_back(a);
    }
    int a, b, c;
    cin >> a >> b >> c;
    vector<int> vis(n+1, 0);
    DFS(G, a, b, c, vis);
    if(vis[b])
        cout << "YES";
    else    
        cout << "NO";
    return 0;
}