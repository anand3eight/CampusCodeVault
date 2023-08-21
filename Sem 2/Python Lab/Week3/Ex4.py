#One's Counter
len = int(input("Enter List Length : "))
ls = list(map(int, input("Enter a binary List : ").strip().split()))[:len]
count = 0
countls = list()
for i in ls :
    if(i == 1) :
        count += 1
    elif(count > 0) :
        countls.append(count)
        count = 0
print(countls)