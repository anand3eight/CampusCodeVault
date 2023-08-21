tup = list()
for i in range(3) :
    elmt = int(input("Enter : "))
    tup.append(elmt)
tup = tuple(tup)
op = '#'
for i in tup :
    op += str(hex(i))
op = op.replace('x','')
op = op.replace('0','')
op = op.upper()
print(op)
