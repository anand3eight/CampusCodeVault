inp = input("Enter Sring  : ")
a = inp[-1 : -len(inp) - 1 : -1]
if(inp[:] == a[:]) :
    print("Palindrome")
else :
    print("Not a Palindrome")
