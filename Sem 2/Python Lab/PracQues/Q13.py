#Message Transmitter

n = int(input("Enter number of Packets : "))
ls = list()
for i in range(n) :
    elmt = list(map(str, input('Enter : ').strip().split()))[:4]
    ls.append(elmt)
idls = [ int(i[0]) + int(i[1]) for i in ls]
idls.sort()
for i in idls :
    for j in ls :
        tot = int(j[0]) + int(j[1])
        if i == tot :
            print(j[3], end = ' ')
    
