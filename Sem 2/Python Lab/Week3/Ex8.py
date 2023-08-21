#Tuple to Zeros

length = int(input("Enter List Length : "))
ls = list(map(int, input("Enter a List : ").strip().split()))[:length]
tup = tuple(ls)
newtup = tup
check = 1
for i in range(1, 100) :
    for j in range(length-1) :
        ls[j] = abs(newtup[j] - newtup[j + 1])
    ls[length - 1] = abs(newtup[length - 2] - newtup[length - 1])
    print(ls)
    newtup = tuple(ls)
    for k in range(length) :
        if(ls[k] == tup[k] or ls[k] == 0) :
            check = 1
        else :
            check = 0
            break
    if(check == 1) :
        print(i)
        exit()
if(check == 0)  :
    print("Invalid Tuple")


