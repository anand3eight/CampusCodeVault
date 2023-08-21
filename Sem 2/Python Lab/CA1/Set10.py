#Disarium
import math
num = input("Enter Number : ")
tot = 0
for i in num :
    tot += pow(int(i), num.index(i) + 1)
print(tot == int(num))