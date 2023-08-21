#Tuple Sum = 7

def zap(ls1, ls2) :
    ls = list()
    for i in ls1 :
        for j in ls2 :
            if i + j == 7:
                ls.append((i,j))
    return ls

n = int(input("Enter List Length : "))
ls1 = list(map(int, input("Enter List 1: ").strip().split()))[:n]
ls2 = list(map(int, input("Enter List 2: ").strip().split()))[:n]
print(zap(ls1, ls2))