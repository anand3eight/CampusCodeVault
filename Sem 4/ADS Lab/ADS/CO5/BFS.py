#Breadth First Search

def BFS(graph, visited, v) :
    q = list()
    q.append(v)
    while(len(q) > 0) :
        t = q.pop(0)
        print(t, end = ' ')
        visited[t] = True
        for i in graph[t] :
            if(visited[i] == False) :
                q.append(i)

n, e = map(int, input('Enter Vertex and Edge Count : ').split())
graph = [[] for i in range(n)]
visited = [False for i in range(n)]
print('Input Edges')
for i in range(e) :
    i, j = map(int, input().split())
    graph[i].append(j)
s = int(input('Source : '))
print('BFS :', end = ' ')
BFS(graph, visited, s)