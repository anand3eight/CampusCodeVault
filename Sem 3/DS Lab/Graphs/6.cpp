// Number of Triangles in an Undirected Graph

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

void triangleCounter(Graph *G)
{
      int aux2[G->v][G->v] = {0};
      int aux3[G->v][G->v] = {0};
      int trace = 0;
      for (int i = 0; i < G->v; i++)
      {
            for (int j = 0; j < G->v; j++)
            {
                  aux2[i][j] = 0;
                  for (int k = 0; k < G->v; k++)
                  {
                        aux2[i][j] += G->dir[i][k] * G->dir[k][j];
                  }
            }
      }

      for (int i = 0; i < G->v; i++)
      {
            for (int j = 0; j < G->v; j++)
            {
                  for (int k = 0; k < G->v; k++)
                  {
                        aux3[i][j] += aux2[i][k] * G->dir[k][j];
                  }
            }
      }

      for (int i = 0; i < G->v; i++)
      {
            trace += aux3[i][i];
      }
      cout << "\nTriangles : " << trace / 6;
}

int main(int argc, char const *argv[])
{
      int x, y, v, ch = 1;
      v = 4;
      Graph *G = createGraph(v);
      int givendir[][2] = {{0, 1},
                           {0, 2},
                           {1, 2},
                           {1, 3},
                           {2, 3}};
      int glen = sizeof(givendir) / sizeof(givendir[0]);
      for (int i = 0; i < glen; i++)
      {
            x = givendir[i][0];
            y = givendir[i][1];
            addEdge(G, x, y);
      }
      printGraph(G);
      triangleCounter(G);
      return 0;
}
