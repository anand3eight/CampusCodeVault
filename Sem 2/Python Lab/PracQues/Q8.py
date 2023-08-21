#Consecutive Sum
n = int(input("Enter : "))
ls = list(map(int, input("Enter List : ").strip().split()))[:n]
tot = 0
for i in range(n) :
    if ls[i] + 1 in ls :
        tot += abs(i - ls.index(ls[i] + 1))
print(tot)
