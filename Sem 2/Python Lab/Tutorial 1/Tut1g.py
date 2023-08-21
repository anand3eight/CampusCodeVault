#Multi Set Printer

n = int(input("Enter Length : "))
org = list()
for i in range(n) :
    elmt = int(input("Enter Element : "))
    org.append(elmt)
mult = list()
for i in range(n) :
    for j in range(i+1, n) :
        elmt = abs(org[i] - org[j])
        mult.append(elmt)
org = set(org)
mult = set(mult)
print(mult)
