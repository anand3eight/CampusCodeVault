#Star Pattern

starlist = list(range(1, 8, 2))
for i in range(3) :
    print(" " * (4 - i), end = ' ')
    print("*" * starlist[i], end = ' ')
    print()
for i in range(1, 5) :
    print(" " * i, end = ' ')
    print("*" * starlist[-i], end = ' ')
    print()
