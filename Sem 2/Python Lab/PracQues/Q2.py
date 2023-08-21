#String Necklace

s1 = input("Enter : ")
s2 = input("Enter : ")
s = s1 * 2
l = len(s1) - 1
if s2 in s :
    print(s1, s2, "Are Necklaces ")
count = 0
for i in range(len(s1)) :
    count += s[i: len(s) - 1].count(s2)
print(count)
    
