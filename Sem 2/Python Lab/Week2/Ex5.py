#SquareFree Check
import math

num = int(input("Enter a Number : "))
lim = int(math.sqrt(num))
check = 0
for i in range(2, lim + 1) :
    if(num % (i*i) == 0):
        check = 1
        print("Not a Square Free Number ")
if(check == 0) :
    print("Square Free Number ")
