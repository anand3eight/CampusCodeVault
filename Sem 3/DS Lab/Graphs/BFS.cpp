// Breadth First Traversal

#include <iostream>
#include <vector>
#include <queue>
#include <cstdlib>

using namespace std;

struct Graph
{
      int v;
      vector<int> *dir;
};

typedef struct Graph Graph;

Graph *createGraph(int v)
{
      Graph *G = new Graph;
      G->v = v;
      G->dir = new vector<int>[v];
      return G;
}

void addEdge(Graph *G, int x, int y)
{
      G->dir[x].push_back(y);
}

void BFS(Graph *G, int s)
{
      int visited[G->v] = {0};
      queue<int> adjacent;
      adjacent.push(s);
      visited[s] = 1;
      while (!adjacent.empty())
      {
            s = adjacent.front();
            cout << s << " ";
            adjacent.pop();
            for (auto &a : G->dir[s])
            {
                  if (!visited[a])
                  {
                        adjacent.push(a);
                        visited[a] = 1;
                  }
            }
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
      cout << "\nBFS : ";
      BFS(G, 2);
      return 0;
}
