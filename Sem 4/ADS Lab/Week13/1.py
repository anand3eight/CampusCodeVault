# You are using Python

def fillOrder(u, visited, stack, graph) :
    visited[u] = 1
    for v in graph[u] :
        if(visited[v] == -1) :
            fillOrder(v, visited, stack, graph)
    stack.append(u)
    
def getTranspose(graph, n) :
    graph2 = [list() for i in range(n)]
    for i in range(n) :
        for j in graph[i] :
            graph2[j].append(i)
    return graph2
    
def DFS(u, visited, graph) :
    visited[u] = 1
    print(u, end = " ")
    for v in graph[u] :
        if visited[v] == -1 :
            DFS(v, visited, graph)
            
def SCC(graph, n) :
    stack = []
    visited = [-1] * n
    for i in range(n) :
        if(visited[i] == -1) :
            fillOrder(i, visited, stack, graph)
    graph2 = getTranspose(graph, n)
    visited = [-1] * n
    while stack :
        i = stack.pop()
        if(visited[i] == -1) :
            DFS(i, visited, graph2)
            print()
    
n = int(input())
graph = [list() for i in range(n)]
for i in range(n) :
    i, j = map(int, input().split())
    graph[i].append(j)
SCC(graph, n)
