#GCD of Two numbers

print("Enter Two Numbers : ")
a = int(input())
b = int(input())
if(a < b):
    while(b % a != 0):
        rem = b % a
        b = a
        a = rem
    print("GCD = ", a)
else :
    while(a % b != 0):
        rem = a % b
        a = b
        b = rem
    print("GCD = ", b)
