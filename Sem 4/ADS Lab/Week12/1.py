# You are using Python

def BFS(adjmat, visited, s) :
    queue = []
    queue.append(s)
    visited[s] = 1
    while(len(queue) > 0) :
        s = queue.pop(0)
        print(s, end = " ")
        for i in adjmat[s] :
            if visited[i] == 0:
                queue.append(i)
                visited[i] = 1
    
v, e = map(int, input().split())
adjmat = [[] for i in range(v)]
    
for k in range(e) :
    i, j = map(int, input().split())
    adjmat[i].append(j)

visited = [0 for i in range(v)]
s = int(input())
BFS(adjmat, visited, s)