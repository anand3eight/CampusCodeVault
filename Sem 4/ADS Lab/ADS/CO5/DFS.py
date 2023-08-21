#Depth First Search

def DFS(graph, visited, v) :
    print(v, end = ' ')
    visited[v] = True
    for i in graph[v] :
        if(visited[i] == False) :
            DFS(graph, visited, i)


n, e = map(int, input('Enter Vertex and Edge Count : ').split())
graph = [[] for i in range(n)]
visited = [False for i in range(n)]
print('Input Edges')
for i in range(e) :
    i, j = map(int, input().split())
    graph[i].append(j)
s = int(input('Source : '))
print('DFS :', end = ' ')
DFS(graph, visited, s)