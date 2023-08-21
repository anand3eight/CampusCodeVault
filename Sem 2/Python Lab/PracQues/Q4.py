num = int(input("Enter Number of Shelves : "))
ls = list(map(int, input("Enter : ").strip().split()))[:num]
bk = list()
for i in range(num) :
    elmt = list(map(str, input("Enter : ").strip().split()))[:2]
    bk.append(elmt)
ls.sort(reverse = True)
tot = 0
shtot = 0
for i in bk :
    tot += int(i[1])
for i in range(len(ls)) :
    shtot = sum(ls[:i + 1])
    if(tot < shtot) :
        print(i + 1)
        break

