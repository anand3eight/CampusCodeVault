#Minimum Number of Subsets

ls = list(map(int, input("Enter List : ").split()))
dc = dict()
mx = 0 
for i in ls :
    dc[i] = 1 if i not in dc else dc[i]+1
    mx = max(mx, dc[i])
print(mx)
