// You are using GCC
#include <iostream>
#include <vector>
using namespace std;
int v, e;

int allVisited(int *visited)
{
    for (int i = 0; i < v; i++)
    {
        if (!visited[i])
            return false;
    }
    return true;
}
int hamiltonianPaths(vector<int> *Graph, int *visited, int s)
{
    visited[s] = 1;
    if (allVisited(visited))
    {
        visited[s] = 0;
        return 1;
    }
    int count = 0;
    for (auto &i : Graph[s])
    {
        if (!visited[i])
            count += hamiltonianPaths(Graph, visited, i);
    }
    visited[s] = 0;
    return count;
}

void countHamiltonianPaths(vector<int> *Graph)
{
    int count = 0;
    int visited[v] = {0};
    for (int i = 0; i < v; i++)
    {
        count += hamiltonianPaths(Graph, visited, i);
    }
    cout << count;
}

int main()
{
    int i, j;
    cin >> v >> e;
    vector<int> graph[v];
    for (int k = 0; k < e; k++)
    {
        cin >> i >> j;
        graph[j].push_back(i);
    }
    countHamiltonianPaths(graph);
    return 0;
}