// Disjoint Paths

#include <iostream>
#include <cstdlib>
#include <queue>

using namespace std;

struct Graph
{
      int v;
      int **dir;
};
typedef struct Graph Graph;

Graph *createGraph(int v)
{
      Graph *G = new Graph;
      G->v = v;
      G->dir = new int *[v];
      for (int i = 0; i < v; i++)
      {
            G->dir[i] = new int[v]{0};
      }
      return G;
}

void addEdge(Graph *G, int x, int y)
{
      G->dir[x][y] = 1;
}

void printGraph(Graph *G)
{
      for (int i = 0; i < G->v; i++)
      {
            for (int j = 0; j < G->v; j++)
            {
                  cout << G->dir[i][j] << " ";
            }
            cout << "\n";
      }
}

bool BFS(int **rdir, int s, int t, int v, int parent[])
{
      int visited[v] = {0};
      queue<int> q;
      q.push(s);
      visited[s] = 1;
      parent[s] = -1;

      while (!q.empty())
      {
            s = q.front();
            q.pop();
            for (int a = 0; a < v; a++)
            {
                  if (!visited[a] && rdir[s][a] > 0)
                  {
                        q.push(a);
                        parent[a] = s;
                        visited[a] = 1;
                  }
            }
      }
      return visited[t] == 1;
}

int disjointPaths(Graph *G, int s, int t)
{
      int u, v;
      int **rdir = new int *[G->v];
      for (int i = 0; i < G->v; i++)
      {
            rdir[i] = new int[G->v]{0};
      }

      int maxFlow = 0;
      int parent[G->v];

      for (u = 0; u < G->v; u++)
      {
            for (v = 0; v < G->v; v++)
            {
                  rdir[u][v] = G->dir[u][v];
            }
      }

      while (BFS(rdir, s, t, G->v, parent))
      {
            int pathFlow = INT_MAX;

            for (v = t; v != s; v = parent[v])
            {
                  u = parent[v];
                  pathFlow = min(pathFlow, rdir[u][v]);
            }
            for (v = t; v != s; v = parent[v])
            {
                  u = parent[v];
                  rdir[u][v] -= pathFlow;
                  rdir[v][u] += pathFlow;
            }
            maxFlow += pathFlow;
      }
      return maxFlow;
}

int main(int argc, char const *argv[])
{
      int x, y, v, ch = 1;
      v = 8;
      Graph *G = createGraph(v);
      int givendir[][2] = {{0, 1},
                           {0, 2},
                           {0, 3},
                           {1, 2},
                           {2, 3},
                           {2, 6},
                           {3, 6},
                           {4, 2},
                           {4, 7},
                           {5, 1},
                           {5, 4},
                           {5, 7},
                           {6, 5},
                           {6, 7}};
      int glen = sizeof(givendir) / sizeof(givendir[0]);
      for (int i = 0; i < glen; i++)
      {
            x = givendir[i][0];
            y = givendir[i][1];
            addEdge(G, x, y);
      }
      cout << "Enter s and t values : ";
      cin >> x >> y;
      cout << "Max Disjoint Paths : " << disjointPaths(G, x, y);

      return 0;
}
