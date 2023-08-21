# Perfect Number

for num in range(1,10000) :
    tot = 0
    for div in range(1,num) :
        if(num % div == 0) :
            tot += div
    if(num == tot) :
        print(num)
