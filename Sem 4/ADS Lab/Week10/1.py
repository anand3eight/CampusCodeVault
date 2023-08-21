# You are using Python
#Naive String Matching
st = input()
pat = input()
for i in range(len(st)-len(pat)+1) :
    if(st[i:i+len(pat)] == pat) :
        print("Pattern found at index", i)