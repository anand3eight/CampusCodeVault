#Automatic Grading System

n, m = map(int, input("Enter N and M : ").strip().split())
ls = list()
for i in range(n) :
    elmtls = list(map(str, input().strip().split()))[:m+1]
    ls.append(elmtls)
avg = 0
for i in ls :
    elmtavg = float(sum([int(i[j]) for j in range(1, m+1)])/m)
    i.append(elmtavg)
    avg += elmtavg
avg /= n
print(avg)
for i in ls :
    print(i[0], i[m+1])
