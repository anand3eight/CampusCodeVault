// to find a SubGraph

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Graph
{
      int v, *visited;
      vector<int> path, *dir;
};

typedef struct Graph Graph;

Graph *createGraph(int v)
{
      Graph *G = new Graph;
      G->v = v;
      G->visited = new int[v]{0};
      G->dir = new vector<int>[v];
      return G;
}

void addEdge(Graph *G, int x, int y)
{
      G->dir[x].push_back(y);
}

void printGraph(Graph *G)
{
      for (int i = 0; i < G->v; i++)
      {
            cout << "\nHead " << i << " -> ";
            for (auto &x : G->dir[i])
            {
                  cout << x << " ";
            }
      }
}

void DFS(Graph *G, int x)
{
      G->visited[x] = 1;
      G->path.push_back(x);
      for (auto &a : G->dir[x])
      {
            if (!G->visited[a])
                  DFS(G, a);
      }
}

void subGraphCheck(Graph *G, int x, int y)
{
      DFS(G, x);
      for (int i = 0; i < G->v; i++)
      {
            if (G->path[i] == y)
            {
                  cout << "Yes";
                  return;
            }
      }
      cout << "No";
}
int main(int argc, char const *argv[])
{
      int x, y, v, ch = 1;
      v = 7;
      Graph *G = createGraph(v);
      int givendir[][2] = {{1, 2},
                           {1, 3},
                           {1, 5},
                           {2, 4},
                           {3, 6}};
      int glen = sizeof(givendir) / sizeof(givendir[0]);
      for (int i = 0; i < glen; i++)
      {
            x = givendir[i][0];
            y = givendir[i][1];
            addEdge(G, x, y);
      }
      printGraph(G);
      cout << "\nEnter x and y Values : ";
      cin >> x >> y;
      subGraphCheck(G, x, y);
      return 0;
}
