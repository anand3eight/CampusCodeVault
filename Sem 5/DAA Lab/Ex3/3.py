#Pair with Required Sum and Maximum Index Difference

ls = list(map(int, input("Enter List : ").split()))
s = int(input("Sum : "))
dc = dict()
for i, j in enumerate(ls) :
    if j not in dc :
        dc[j] = [i]
    else :
        dc[j].append(i)
mx = 0
val = int()
for i in ls :
    if s-i in dc :
        if mx < dc[i][0]-dc[s-i][-1]:
            mx = dc[i][-1]-dc[s-i][-1]
            val = i
print(f"{val}, {s-val}")
    
