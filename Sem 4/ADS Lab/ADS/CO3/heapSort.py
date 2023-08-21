#Inplace Sorting using MaxHeap

def Heapify(tree, n, i) :
    b, l, r = i, 2*i+1, 2*i+2
    if(l < n and tree[l] > tree[b]) :
        b = l
    if(r < n and tree[r] > tree[b]) :
        b = r
    if(b != i) :
        tree[b], tree[i] = tree[i], tree[b]
        Heapify(tree, n, b)

def heapSort(tree, n) :
    start = n // 2 - 1
    stop = -1
    step = -1
    for i in range(start, stop, step) :
        Heapify(tree, n, i)

    for i in range(n-1, -1, -1) :
        tree[0], tree[i] = tree[i], tree[0]
        Heapify(tree, i, 0)

if __name__ == '__main__' :
    tree = list(map(int, input("Enter Level Order of Tree : ").split()))
    n = len(tree)
    heapSort(tree, n)
    print(f"After HeapSort : {tree}")