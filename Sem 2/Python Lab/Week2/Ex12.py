#Rock Paper Scissors
import random

for i in range(5) :
    randno = random.randint(1,3)
    if(randno == 1) : print("Rock")
    elif(randno == 2) : print("Paper")
    elif(randno == 3) : print("Scissor")

for i in range(5) :
    ch = int(input("Enter in Range 1-3 : "))
    if(ch == 1) : print("Rock")
    elif(ch == 2) : print("Paper")
    elif(ch == 3) : print("Scissor")
