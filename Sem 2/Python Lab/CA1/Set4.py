#List Arrangement

n = int(input("Enter List Length : "))
ls = list(map(int, input("Enter : ").strip().split()))[:n]
pos = list()
neg = list()
for i in ls :
    if i < 0 :
        neg.append(i)
    else :
        pos.append(i)
l = len(pos) if len(pos) < len(neg) else len(neg)
for i in range(l) :
    print(pos[i], neg[i], end = ' ')