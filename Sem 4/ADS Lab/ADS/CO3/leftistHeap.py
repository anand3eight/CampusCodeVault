#Leftist Heaps

class Node :
    def __init__(self, val):
        self.x = val
        self.left = None
        self.right = None
        self.npl = 0

class leftistHeap :
    def __init__(self):
        self.root = None
    def merge(self, heap1, heap2):
        if not heap1 :
            return heap2
        if not heap2 :
            return heap1
        if heap1.x > heap2.x :
            heap1, heap2 = heap2, heap1

        heap1.right = self.merge(heap1.right, heap2)
        if heap1.left is None :
            heap1.left = heap1.right
            heap1.right = None
        else :
            if heap1.left.npl < heap1.right.npl :
                heap1.left, heap1.right = heap1.right, heap1.left
            heap1.npl = heap1.right.npl + 1
        return heap1

    def insert(self, val):
        n = Node(val)
        self.root = self.merge(self.root, n)

    def deleteMin(self):
        if not self.root :
            return None
        m = self.root.x
        self.root = self.merge(self.root.left, self.root.right)
        return m

def inputTree() :
    val = int(input("Enter Value : "))
    if val == -1 :
        return None
    n = Node(val)
    print(f'Left Child of {val}', end = " ")
    n.left = inputTree()
    print(f'Right Child of {val}', end = " ")
    n.right = inputTree()
    return n

def levelOrder(n) :
    if n :
        print("Heap : ", end = "")
        q = list()
        q.append(n)
        while(len(q) > 0) :
            t = q[0]
            print(t.x, end = " ")
            if t.left :
                q.append(t.left)
            if t.right :
                q.append(t.right)
            q.pop(0)
        print()


if __name__ == '__main__' :
    heap = leftistHeap()
    print("1 : Merge \n2 : Insert \n3 : Delete \n-1 : Exit")
    ch = 0
    while(ch != -1) :
        ch = int(input("Enter your Choice : "))
        if ch == 1 :
            print("Heap1")
            heap1 = inputTree()
            print("Heap2")
            heap2 = inputTree()
            heap1 = heap.merge(heap1, heap2)
            print("Output : ")
            levelOrder(heap1)
        if ch == 2 :
            heap.insert(int(input("Enter Value : ")))
            print("Output : ")
            levelOrder(heap.root)
        if ch == 3 :
            print(f"Min Value : {heap.deleteMin()}")
            print("Output : ")
            levelOrder(heap.root)
