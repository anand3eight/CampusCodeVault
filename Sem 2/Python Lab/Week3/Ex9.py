#Blood Donor

n = int(input("Enter Number of Donors : "))
ls = list()
for i in range(n) :
    name = input("Enter Name : ")
    grp = input("Enter Blood Group : ")
    age = int(input("Enter Age : "))
    ls.append((name, grp, age))

print("Enter Requirements : ")
grp = input("Enter Blood Group : ")
age = int(input("Enter Age : "))
id = 0
agediff = age
for i in ls :
    if grp in i :
        if abs(age - i[2]) < agediff :
            id = ls.index(i)
print(ls[id])