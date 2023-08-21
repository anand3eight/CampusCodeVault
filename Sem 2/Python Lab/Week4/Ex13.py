inp1 = input("Enter String 1 : ")
inp2 = input("Enter String 2 : ")
res = ''
if(len(inp1) == len(inp2)) :
    for i in range(len(inp1)) :
        res += inp2[i] + inp1[i]
    print(res)
else :
    print("Not Possible")
