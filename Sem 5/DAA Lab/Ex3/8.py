#Line with Most Points

n = int(input("Number of Points : "))
ls = list()
for i in range(n) :
    i = list(map(int, input().split()))[:2]
    ls.append(i)
mx = 0
for i in range(n) :
    dc = dict()
    for j in range(i+1, n) :
        try :
            slope = (ls[j][1]-ls[i][1])/(ls[j][0]-ls[i][0])
        except ZeroDivisionError :
            continue
        if slope not in dc :
            dc[slope] = 2
        else :
            dc[slope] += 1
        mx = max(mx, dc[slope])
print(mx)
