#Sort Binary Array

n = int(input("Enter List Length : "))
ls = list(map(int, input("Enter Binary Array: ").strip().split()))[:n]
ls.sort()
print(ls)