// Depth First Traversal

#include <iostream>
#include <vector>
#include <cstdlib>

using namespace std;

struct Graph
{
      int v, *visited;
      vector<int> *dir;
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
      cout << x << " ";
      for (auto &a : G->dir[x])
      {
            if (!G->visited[a])
                  DFS(G, a);
      }
}
int main(int argc, char const *argv[])
{
      int x, y, v, ch = 1;
      v = 4;
      Graph *G = createGraph(v);
      int givendir[][2] = {{0, 1},
                           {0, 2},
                           {1, 2},
                           {2, 0},
                           {2, 3},
                           {3, 3}};
      int glen = sizeof(givendir) / sizeof(givendir[0]);
      for (int i = 0; i < glen; i++)
      {
            x = givendir[i][0];
            y = givendir[i][1];
            addEdge(G, x, y);
      }
      printGraph(G);
      cout << "\nDFS : ";
      DFS(G, 1);

      return 0;
}
