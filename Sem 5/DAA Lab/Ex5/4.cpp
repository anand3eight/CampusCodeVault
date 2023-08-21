//WiFi Access Point Checks

#include<iostream>
#include<queue>
#include<cstdlib>
using namespace std;

void BFS(vector<vector<int> > G, int j, int th){
    int s = G.size(), c = 0;
    int *vis = (int*)calloc(sizeof(int), s);
    queue<int> q;
    q.push(j);
    vis[j] = 1;
    while(!q.empty() and c < th){
        int t = q.front();
        q.pop();
        for(int i = 0; i < s; i++){
            if(G[t][i] == 1 and vis[i] == 0)
            {
                q.push(i);
                cout << i << " ";
                vis[i] = 1;
            }
        }
        c++;
    }
}
int main(){
    int v, e, j, th, a, b;
    cin >> v >> e;
    cin >> j >> th;
    vector<vector<int> > G(v+1, vector<int>(v+1, 0));
    for(int i = 0; i < e; i++){
        cin >> a >> b;
        G[a][b] = G[b][a] = 1;
    }
    BFS(G, j, th);
    return 0;
}