#Reversing a List and Swapping values
n = int(input("Enter Length of List : "))
ls = list(map(int, input("Enter Numbers : ").strip().split()))[:n]
newls = ls
for i in range(-1, -n-1, -1) :
    print(ls[i], end = ' ')
start = int(input("\nEnter Start : "))
stop = int(input("Enter Stop : "))
if(start in list(range(n)) and stop in list(range(n))) :
    temp = newls[start]
    newls[start] = newls[stop]
    newls[stop] = temp
print(newls)