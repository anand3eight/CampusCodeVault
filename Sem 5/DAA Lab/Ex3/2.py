#Pictogram

inp = input("Enter String : ").upper()
dc = dict()
for i in inp :
    if i.isalpha() :
        dc[i] = 1 if i not in dc else dc[i] + 1
for k in dc :
    print(f"{k}-{dc[k]}, ", end = "")

