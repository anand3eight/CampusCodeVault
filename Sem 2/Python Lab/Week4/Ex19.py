inp = input("Enter Larger Number : ")
res = inp[:len(inp)%3]
for i in range(len(inp)%3, len(inp), 3) :
    res += ',' + inp[i:i+3] 
print(res)
