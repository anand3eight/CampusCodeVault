// Type of Graph

#include <iostream>
#include <cstdlib>

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
      G->dir[y][x] = 1;
}

int strongGraph(Graph *G)
{
      for (int i = 0; i < G->v; i++)
      {
            for (int j = 0; j < G->v; j++)
            {
                  if (G->dir[i][j] != 1)
                        return 0;
            }
      }
      return 1;
}

int uniGraph(Graph *G)
{
      for (int i = 0; i < G->v; i++)
      {
            for (int j = 0; j < G->v; j++)
            {
                  if (G->dir[i][i] == 1 || ((i != j) && G->dir[i][j] != 1))
                        return 0;
            }
      }
      return 1;
}
void graphCheck(Graph *G)
{
      if (strongGraph(G))
            cout << "Strongly Connected";
      else if (uniGraph(G))
            cout << "Unilaterally Connected";
      else
            cout << "Weakly Connected";
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

int main(int argc, char const *argv[])
{
      int x, y, v, ch = 1;
      cout << "Enter Number of Vertices : ";
      cin >> v;
      Graph *G = createGraph(v);
      while (ch)
      {
            cout << "Enter x and y : ";
            cin >> x >> y;
            addEdge(G, x, y);
            cout << "To End -> Press 0 : ";
            cin >> ch;
      }
      printGraph(G);
      graphCheck(G);
      return 0;
}
