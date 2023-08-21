def Heapify(ls, n, i) :
    b = i
    l = 2*i+1
    r = l + 1
    if(l < n and ls[b] > ls[l]) :
        b = l
    if(r < n and ls[b] > ls[r]) :
        b = r
    if(b != i) :
        ls[b], ls[i] = ls[i], ls[b]
        Heapify(ls, n, b)
        
def HeapSort(ls, n) :
    start = n//2 - 1;
    stop = -1
    step = -1
    for i in range(start, stop, step) :
        Heapify(ls, n, i)
        
    for i in range(n-1, stop, step) :
        ls[i], ls[0] = ls[0], ls[i]
        Heapify(ls, i, 0)
    return ls    
if __name__ == "__main__" :
    n = int(input())
    ls = list(map(int, input().split()))[:n]
    print("Sorted array is")
    for i in HeapSort(ls, n) :
        print(i, end = " ")
        