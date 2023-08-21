#Random Game
import random

amt = 100
while(amt > 0 and amt <= 200):
    num = int(input("Enter a Heads/Tails -> (1- heads/2- tails) : "))
    rand = random.randint(1,2)
    print(rand)
    if(rand == num): amt += 9
    else :  amt -= 10
print("Amount Left = ", amt)
