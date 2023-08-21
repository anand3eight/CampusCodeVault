#City Skyline

def skyline(ls) :
    for row in ls :
        if 1 in row:
            return len(ls) - ls.index(row)

n = int(input("Enter Number of Buildings : "))
ls = list()
for i in range(n) :
    elmt = list(map(int, input("Enter : ").strip().split()))
    ls.append(elmt)
print(skyline(ls))