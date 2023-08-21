#Lookup Table List

ls = list()
for i in range(8) :
    ls.append(3*i + 2)
print(ls)

len = int(input("Enter List Length : "))
inputls = list(map(int, input("Enter a List : ").strip().split()))[:len]
for i in inputls:
    print(ls[i], end = ' ')