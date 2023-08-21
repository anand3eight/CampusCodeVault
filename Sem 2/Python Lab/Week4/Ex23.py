#Rail Cipher Method

st = input("Enter : ")
n = int(input("Enter Number : "))
ls = list()
dc = dict()
dc[0] = ''
for i in range(n) :
    elmt = st[i::n]
    ls.append(elmt)
    print(elmt, end='')
    if(i + 1 < n) : dc[i + 1] = dc[i] + elmt[-1]
print()
for i in range(int(len(st)/n)) :
    for j in range(n) :
        print(ls[j][i], end = "")
print(dc[len(st) % n])
