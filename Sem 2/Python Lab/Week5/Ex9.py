#String Match

def match(s1, s2) :
    tot = 0
    for i in s1 :
        if(i in s2 and s1.index(i) == s2.index(i)) :
            tot += 1
    return tot

s1 = input("Enter : ")
s2 = input("Enter : ")
if(len(s1) < len(s2)) : print(match(s1, s2))
else : print(match(s2, s1))