#Merge Sort

def merge(l1, l2):
    l = len(l1) + len(l2)
    net = list()
    j, k = 0, 0
    for i in range(l) :
        if(j < len(l1) and k <= len(l2) and l1[j] < l2[k]) :
            net.append(l1[j])
            j += 1
        elif(j <= len(l1) and k < len(l2)):
            net.append(l2[k])
            k += 1
    return net

n1 = int(input("Enter List1 Length : "))
n2 = int(input("Enter List2 Length : "))
l1 = list(map(int, input("Enter list 1: ").strip().split()))[:n1]
l2 = list(map(int, input("Enter list 2: ").strip().split()))[:n2]
l1.sort()
l2.sort()
print(merge(l1, l2))