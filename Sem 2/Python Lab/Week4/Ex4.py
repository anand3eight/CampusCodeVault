vow = ['a', 'e', 'i', 'o', 'u', 'A', 'E', 'I', 'O', 'U']
inp = input("Enter String  : ")
ch = 0
for i in inp :
    if i in vow :
        ch = 1
        print("Vowel Exists")
        break
if ch == 0 :
    print("Vowel does not Exist")
