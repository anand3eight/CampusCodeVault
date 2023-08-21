#Maximum Distance between Same elements

ls = list(map(int, input("Enter List : ").split()))
dc = dict()
mx = 0
for i, j in enumerate(ls) :
    if j not in dc :
        dc[j] = i
    else :
        mx = max(mx, i-dc[j])
print(mx)
