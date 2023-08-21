# You are using Python
def heapifyy(ls, i) :
    n = len(ls)
    b = i
    l = 2*i+1
    r = 2*i+2
    if(l < n and ls[l] > ls[b]) :
        b = l
    if(r < n and ls[r] > ls[b]) :
        b = r
    if(b != i) :
        ls[i], ls[b] = ls[b], ls[i]
        heapifyy(ls, b)
def maxheap(ls) :
    n = len(ls)
    start = int(n/2 - 1)
    end = -1
    step = -1
    for i in range(start, end, step) :
        heapifyy(ls, i)
    print("Max Heap array :", end = " ")
    for i in ls :
        print(i, end = " ")
n = int(input())
minh = list(map(int, input().split()))[:n]
print("Min Heap array :", end = " ")
for i in minh :
    print(i, end = " ")
print()
maxheap(minh) 
    