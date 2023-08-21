#Karaca's Algorithm

dc = {'a' : '0', 'e' : '1', 'i' : '2', 'o' : '2', 'u' : '3'}
st = input("Enter : ").lower()
op = st[-1: -len(st)-1 : -1]
ls = list(dc.keys())
for i in op :
    if i in ls :
        op = op.replace(i, dc[i])
op += 'aca'
print(op)
