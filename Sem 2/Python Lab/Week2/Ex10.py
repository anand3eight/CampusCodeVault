#Number Check

p = 0
n = 0
z = 0
tot = 0
for i in range(7):
    num = int(input("Enter : "))
    if(num > 0) : p += 1
    elif(num == 0) : z += 1
    else : n += 1
    tot += num
print(p, n, z, tot)
