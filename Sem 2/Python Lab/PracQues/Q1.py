#Number Count

n = int(input("Enter : "))
dc = dict()
for i in range(1, n+1) :
    while(i > 0) :
        rem = i%10
        if rem in dc :
            dc[rem] += 1
        else :
            dc[rem] = 1
        i = int(i/10)
print(dc)
