def heapify(ls, n, i) :
    b = i
    l = 2*i+1
    r = l + 1
    if(l < n and ls[b] < ls[l]) :
        b = l
    if(r < n and ls[b] < ls[r]) :
        b = r
    if(b != i) :
        ls[b], ls[i] = ls[i], ls[b]
        heapify(ls, n, b)

def maxHeap(ls) :
    n = len(ls)
    start = n//2 - 1
    stop = -1
    step = -1
    for i in range(start, stop, step) :
        heapify(ls, n, i)
    return ls

def derangement(ls) :
    n = len(ls)
    maxh = list()
    for i in ls :
        maxh.append(i)
    derangeSequence = []
    for i in range(n) :
        maxh = maxHeap(maxh)
        d = maxh[0]
        del maxh[0]
        if(i == n-1 or d != ls[i]) :
            derangeSequence.append(d) 
        else :
            maxh = maxHeap(maxh)
            derangeSequence.append(maxh[0])
            del maxh[0]
            maxh.append(d)
    
    if ls[n-1] == derangeSequence[n-1] :
        derangeSequence[n-1], derangeSequence[n-2] = derangeSequence[n-2], derangeSequence[n-1]
    return derangeSequence
n = int(input())
ls = list(map(int, input().split()))[:n]
print("Largest Derangement")
for i in derangement(ls) :
    print(i, end = " ")