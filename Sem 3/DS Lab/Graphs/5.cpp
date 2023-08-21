// Lexicographical Traversal

#include <iostream>
#include <map>
#include <set>
#include <cstdlib>

using namespace std;

struct Graph
{
      int v;
      map<char, set<char>> dir;
      map<char, int> visited;
};

typedef struct Graph Graph;

Graph *createGraph(int v)
{
      Graph *G = new Graph;
      G->v = v;
      return G;
}

void addEdge(Graph *G, char x, char y)
{
      G->dir[x].insert(y);
}

void DFS(Graph *G, char x)
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
      int v, ch = 1;
      char x, y;
      v = 11;
      Graph *G = createGraph(v);
      char givendir[][2] = {{'a', 'z'},
                            {'a', 'y'},
                            {'a', 'p'},
                            {'z', 'g'},
                            {'z', 'i'},
                            {'z', 'h'},
                            {'y', 'm'},
                            {'y', 'l'},
                            {'p', 'c'},
                            {'p', 'b'}};
      int glen = sizeof(givendir) / sizeof(givendir[0]);
      for (int i = 0; i < glen; i++)
      {
            x = givendir[i][0];
            y = givendir[i][1];
            addEdge(G, x, y);
      }
      cout << "\nDFS : ";
      DFS(G, 'a');

      return 0;
}
