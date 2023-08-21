#sum of digits

def sum_digits(num) :
    tot = 0
    while(num > 0) :
        rem = num % 10
        tot += rem
        num = int(num /10)
    return tot
n = int(input("Enter : "))
print(sum_digits(n))
