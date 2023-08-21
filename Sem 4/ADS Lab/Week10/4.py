# You are using Python
#RabinKarp String matching
def hashfun(st) :
    h = 0
    for i in st :
        h += ord(i)
    return h

txt = input()
pat = input()
ph,m,n = hashfun(pat),len(pat),len(txt)
for i in range(n-m+1) :
    th = hashfun(txt[i:i+m])
    if th == ph :
        if(txt[i:i+m] == pat) :
            print("Pattern found at index", i)