# Topological Sort

def topoSortUtil(graph, visited, stack, v) :
    visited[v] = True
    for i in graph[v] :
        if(visited[i] == False) :
            topoSortUtil(graph, visited, stack, i)
    stack.append(v)

def topoSort(graph, n) :
    stack = []
    visited = [False for i in range(n)]
    for i in range(n) :
        if(visited[i] == False) :
            topoSortUtil(graph, visited, stack, i)
    print("Topological Sort :", (stack[::-1]))


n, e = map(int, input('Enter Vertex and Edge Count : ').split())
graph = [[] for i in range(n)]
print('Input Edges')
for i in range(e) :
    i, j = map(int, input().split())
    graph[i].append(j)
topoSort(graph, n)