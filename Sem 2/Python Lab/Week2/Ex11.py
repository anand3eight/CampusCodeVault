#Random Guess

import random

trylim = 4
randnum = random.randint(0,100)
for i in range(trylim) :
    num = int(input("Enter Guess : "))
    if(num == randnum) :
        print("Perfect!")
        break
    elif(num - 10 > randnum) : print("Much higher ")
    elif(num > randnum) : print("Higher ")
    elif(num + 10 < randnum) : print("Much Lower ")
    elif(num < randnum) : print("Lower ")
print("Correct Guess : ", randnum)
