// Adjacency List Representation

#include <iostream>
#include <vector>
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
      G->dir[y].push_back(x);
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

      return 0;
}
