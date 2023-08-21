#Euler path and Circuit

def DFS(graph, u, vis) :
    c = 1
    vis[u] = True
    for i in graph[u] :
        if vis[i] == False :
            c += DFS(graph, i, vis)
    return c

def validEdge(graph, u, v) :
    if(len(graph[u]) == 1) :
        return True
    else :
        vis = [False] * len(graph)
        c1 = DFS(graph, u, vis)
        graph[u].pop(graph[u].index(v))
        graph[v].pop(graph[v].index(u))
        c2 = DFS(graph, u, vis)
        graph[u].append(v)
        graph[v].append(u)
        return c1 > c2

def eulerCycleUtil(graph, u) :
    for v in graph[u] :
        if validEdge(graph, u, v) :
            print(f'{u}-{v}', end = ' ')
            graph[u].pop(graph[u].index(v))
            graph[v].pop(graph[v].index(u))
            eulerCycleUtil(graph, v)

def eulerCycle(graph, n) :
    u = 0
    for i in range(n) :
        if(len(graph[i]) % 2 == 1) :
            u = i
            break
    eulerCycleUtil(graph, u)

n, e = map(int, input('Enter Vertex and Edge Count : ').split())
graph = [[]*n for i in range(n)]
print('Input Edges')
for i in range(e) :
    i, j = map(int, input().split())
    graph[i].append(j)
    graph[j].append(i)
eulerCycle(graph, n)
