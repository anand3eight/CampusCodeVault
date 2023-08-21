#Smallest subarray with Most frequent elements

ls = list(map(int, input("Enter List : ").split()))
dc = dict()
mx = 0
ans = int()
for i, j in enumerate(ls) :
    if j not in dc :
        dc[j] = [i]
    else :
        dc[j].append(i)
        if mx < len(dc[j]) :
            mx = len(dc[j])
            ans = j
print(ls[dc[ans][0] : dc[ans][-1]+1]) 
            
