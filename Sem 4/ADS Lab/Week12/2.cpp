// You are using GCC
#include <iostream>
#include <vector>
using namespace std;
int v, e;
void DFS(vector<int> *adjmat, int *visited, int s)
{
    cout << s << " ";
    visited[s] = 1;
    for (auto &a : adjmat[s])
    {
        if (!visited[a])
        {
            DFS(adjmat, visited, a);
        }
    }
}

int main()
{
    int i, j;
    cin >> v >> e;
    vector<int> adjmat[v];
    int visited[v] = {0};
    for (int k = 0; k < e; k++)
    {
        cin >> i >> j;
        adjmat[i].push_back(j);
    }
    cin >> i;
    DFS(adjmat, visited, i);
    return 0;
}