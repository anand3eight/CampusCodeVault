// Degree of Vertex

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

int degree(Graph *G, int ver)
{
      int deg = 0;
      for (int j = 0; j < G->v; j++)
      {
            if (G->dir[ver][j] == 1)
                  deg++;
      }
      return deg;
}

int main(int argc, char const *argv[])
{
      int x, y, v, ver, ch = 1;
      v = 4;
      Graph *G = createGraph(v);
      int givendir[][2] = {{0, 1},
                           {0, 2},
                           {0, 3},
                           {1, 0},
                           {1, 3},
                           {2, 0},
                           {2, 3},
                           {3, 0},
                           {3, 1},
                           {3, 2}};
      int glen = sizeof(givendir) / sizeof(givendir[0]);
      for (int i = 0; i < glen; i++)
      {
            x = givendir[i][0];
            y = givendir[i][1];
            addEdge(G, x, y);
      }
      printGraph(G);
      cout << "Enter Search Vertex : ";
      cin >> ver;
      cout << "Degree of " << ver << " is " << degree(G, ver);
      return 0;
}
