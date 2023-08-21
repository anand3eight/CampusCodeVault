# Set Operations

n = int(input("Enter Value for n : "))
uset = set(range(1,n + 1))
lset1 = int(input("Enter Set 1 Length : "))
set1 = list()
for i in range(lset1) :
    elmt  = int(input("Enter : "))
    set1.append(elmt)
set1 = set(set1)
lset2 = int(input("Enter Set 2 Length : "))
set2 = list()
for i in range(lset2) :
    elmt  = int(input("Enter : "))
    set2.append(elmt)
set2 = set(set2)

print(set1,"\n", set2)
print(set1.union(set2))
print(set1.intersection(set2))
print(set1.difference(set2))
print(set2.difference(set1))

for elmt in uset :
    if(elmt not in set1) :
        print(elmt, end = " " )
print()
for elmt in uset :
    if(elmt not in set2) :
        print(elmt, end = " " )
