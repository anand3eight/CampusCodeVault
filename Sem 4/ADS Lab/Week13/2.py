# You are using Python
count = 0
time = 0
def BCCUtil(u, parent, low, disc, st, graph) :
    children = 0
    global time
    disc[u] = time
    low[u] = time
    time += 1
    for v in graph[u] :
        if disc[v] == -1 :
            parent[v] = u
            children += 1
            st.append((u,v))
            BCCUtil(v, parent, low, disc, st, graph)
            low[u] = min(low[u], low[v])
            
            if (parent[u] == -1 and children  > 1) or (parent[u] != -1 and low[v] >= disc[u]) :
                global count
                count += 1
                w = -1
                while(w != (u,v)) :
                    w = st.pop()
                    print(w, end = " ")
                print()
        elif v != parent[u] and low[u] > disc[v] :
            low[u] = min(low[u], disc[v])
            st.append((u,v))
 
def BCC(graph, n) :                    
    disc= [-1]*n
    low = [-1]*n
    parent = [-1]*n
    st = []
    
    for i in range(n) :
        if disc[i] == -1 :
            BCCUtil(i, parent, low, disc, st, graph)
            
        if st :
            global count
            count += 1
            while st :
                print(st.pop(), end = " ")
            print()
            
n = int(input())
inp = input()
graph = [list() for i in range(n)]
while(inp != "done"):
    i, j = map(int, inp.split(" "))
    try :
        graph[i].append(j)
        graph[j].append(i)
    except IndexError :
        s = 1
    inp = input()

BCC(graph, n)
print("Above are", count, "biconnected components in the graph")
