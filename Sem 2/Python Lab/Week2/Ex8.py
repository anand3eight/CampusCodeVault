#Random Rectangle

print("Enter Length And breadth of a Rectangle : ")
l, b = int(input()), int(input())
num = 0
for i in range(l):
    for j in range(b):
        print(num, end = ' ')
        num += 1
        if(num == 10): num = 0
    print()
