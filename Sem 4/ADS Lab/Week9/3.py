# You are using Python
def Heapify(ls, n, i) :
    s = i
    l = 2*i+1
    r = l+1
    if(l < n and ls[l] < ls[s]) :
        s = l
    if(r < n and ls[r] < ls[s]) :
        s = r
    if s != i :
        ls[s], ls[i] = ls[i], ls[s]
        Heapify(ls, n, s)

def minHeap(ls) :
    n = len(ls)
    start = n//2 - 1
    stop = -1
    step = -1
    for i in range(start, stop, step) :
        Heapify(ls, n, i)
    return ls

def minCost(ls, n) :
    minh = ls
    res = 0
    while(len(minh) > 1) :
        minh = minHeap(minh)
        x = minh[0]
        del minh[0]
        minh = minHeap(minh)
        y = minh[0]
        del minh[0]
        res += x+y
        minh.append(x+y)
    return res
    
n = int(input())
ls = list(map(int, input().split()))[:n]
print("Total cost for connecting ropes is", minCost(ls, n))
        