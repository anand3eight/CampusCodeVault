#Odd and Even Numbers
ls = list()
for i in range(int(input("Enter Length : "))):
    elmt = int(input("Enter : "))
    ls.append(elmt)
tot = 0
for i in ls :
    if(i % 2) : i = i * 5
    else : i = i * 3
    tot += i
print(tot)
