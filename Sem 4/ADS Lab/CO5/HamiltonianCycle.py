#Hamiltonian Cycle/Circuit

def hamCheck(graph, path, pos, n) :
    if pos == n :
        return graph[path[pos-1]][path[0]] == 1

    for i in range(1, n) :
        if (graph[path[pos-1]][i] == 1) and (i not in path):
            path[pos] = i
            if hamCheck(graph, path, pos+1, n) == True :
                return True
            path[pos] = -1
    return False
def hamCycle(graph, n) :
    path = [-1] * n
    path[0] = 0
    if(hamCheck(graph, path, 1, n) == True):
        print('HamCycle : ', end = ' ')
        for i in path :
            print(i, end = ' ')
        print(path[0])
    else :
        print('HamCycle does not Exist')


n, e = map(int, input('Enter Vertex and Edge Count : ').split())
graph = [[0]*n for i in range(n)]
print('Input Edges')
for i in range(e) :
    i, j = map(int, input().split())
    graph[i][j] = 1
hamCycle(graph, n)
