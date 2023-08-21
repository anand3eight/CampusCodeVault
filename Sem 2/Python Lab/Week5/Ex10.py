#List of Factors

def factors(num) :
    ls = list()
    for i in range(1, num + 1) :
        if(num % i == 0) :
            ls.append(i)
    return ls

num = int(input("Enter Number : "))
print(factors(num))