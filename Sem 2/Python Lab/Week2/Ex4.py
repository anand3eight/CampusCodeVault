#Pascal Triangle
from math import factorial as fact

for i in range(7) :
    for j in range(i+1) :
        print(int(fact(i)/(fact(i-j)*fact(j))), end = ' ')
    print()