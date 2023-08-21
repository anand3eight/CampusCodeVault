inp = input("Enter String : ")
res = ''
for i in range(1, len(inp), 2) :
    res = res + inp[i-1] + inp[i].upper()
print(res)
