#MinHeap

def Heapify(tree, n, i) :
    b, l, r = i, 2*i+1, 2*i+2
    if(l < n and tree[l] < tree[b]) :
        b = l
    if(r < n and tree[r] < tree[b]) :
        b = r
    if(b != i) :
        tree[b], tree[i] = tree[i], tree[b]
        Heapify(tree, n, b)

def minHeap(tree, n) :
    start = n // 2 - 1
    stop = -1
    step = -1
    for i in range(start, stop, step) :
        Heapify(tree, n, i)

if __name__ == '__main__' :
    tree = list(map(int, input("Enter Level Order of Tree : ").split()))
    n = len(tree)
    minHeap(tree, n)
    print(f"MinHeap Tree : {tree}")