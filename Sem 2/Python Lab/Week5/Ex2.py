#Strings Check

def check(s1, s2, l) :
    for i in range(l) :
        if(s1[i] != s2[i]) : return i
    return -1
s1 = input("Enter String 1 : ")
s2 = input("Enter String 2 : ")
if(len(s1) == len(s2)) : print(check(s1,s2,len(s1)))
else : print(check(s1,s2, max(len(s1), len(s2))))
