# You are using Python
def heapifyy(ls, i) :
    n = len(ls)
    b = i
    l = 2*i+1
    r = l+1
    if(l<n and ls[l] > ls[b]) :
        b = l
    if(r<n and ls[r] > ls[b]) :
        b = r
    if b != i :
        ls[b], ls[i] = ls[i], ls[b]
        heapifyy(ls, b)
    
def maxheap(ls) :
    n = len(ls)
    start = n//2 - 1
    stop = -1
    step = -1
    for i in range(start, stop, step) :
        heapifyy(ls, i)
    return ls[0]
    
n = int(input())
ls = list(map(int, input().split()))[:n]
q = list()
for i in range(n) :
    q.append(ls[i])
    if len(q) < 3 :
        print(-1)
    else :
        x = maxheap(q)
        del q[0]
        y = maxheap(q)
        del q[0]
        z = maxheap(q)
        del q[0]
        print(x * y * z)
        q.append(x)
        q.append(y)
        q.append(z)