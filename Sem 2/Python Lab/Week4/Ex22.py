#Encoder and Decoder

st = input("Enter : ")
s1 = st[::2]
s2 = st[1::2]
print(s1 + s2)
if(len(st) % 2) :
    for i in range(len(s1) - 1) :
        print(s1[i]+s2[i], end = "")
    print(s1[-1])
else :
    for i in range(len(s1)) :
        print(s1[i]+s2[i], end = "")