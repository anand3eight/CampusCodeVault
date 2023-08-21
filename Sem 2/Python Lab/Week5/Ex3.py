#Number List Check

def closest(ls, n, ln) :
    for i in range(-1, -ln-1, -1) :
        if(ls[i] < n ) :
            return ls[i]
        


ln = int(input("Enter length : "))
ls = list()
for i in range(ln) :
    elmt = int(input("Enter : "))
    ls.append(elmt)
ls.sort()
n = int(input("Enter Value for n : "))
print(closest(ls, n, ln))
