#Centered Average

ls = list()
for i in range(int(input("Enter Length : "))):
    elmt = int(input("Enter : "))
    ls.append(elmt)
ls.sort()
print(sum(ls[1:len(ls)])/len(ls[1:len(ls)]))
    
