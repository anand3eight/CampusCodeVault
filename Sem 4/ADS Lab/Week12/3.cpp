// You are using GCC
#include <iostream>
#include <vector>
#include <stack>
#include <unordered_map>
using namespace std;
int v, e;
stack<int> st;

void DFS(vector<int> *adjmat, int *visited, int s)
{
    visited[s] = 1;
    for (auto &i : adjmat[s])
    {
        if (!visited[i])
        {
            DFS(adjmat, visited, i);
        }
    }
    st.push(s);
}

void cycleCheck(vector<int> *adjmat, int s)
{
    int visited[v] = {0};
    DFS(adjmat, visited, s);
    int pos[v], ind = 0;
    while (!st.empty())
    {
        pos[st.top()] = ind++;
        st.pop();
    }
    for (int i = 0; i < v; i++)
    {
        for (auto &j : adjmat[i])
        {
            if (pos[i] > pos[j])
            {
                cout << "Yes";
                return;
            }
        }
    }
    cout << "No";
}

int main()
{
    int i, j;
    cin >> v >> e;
    vector<int> adjmat[v];
    for (int k = 0; k < e; k++)
    {
        cin >> i >> j;
        adjmat[i].push_back(j);
    }
    cycleCheck(adjmat, 0);
    return 0;
}