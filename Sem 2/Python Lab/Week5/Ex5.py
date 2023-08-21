#Word Sum

def wordsum(st,start = 0) :
    tot = 0
    for i in st :
        tot += (ord(i) - 96 + start)
    return tot
st = input("Enter : ")
start = int(input("Enter Start Value : "))
print(wordsum(st,start))