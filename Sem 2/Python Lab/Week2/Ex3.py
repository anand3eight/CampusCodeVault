#NEXTGEN problem

power = int(input("Enter Power Required : "))
years = int(input("Enter Number of Years Taken : "))
helium = int(input("Enter Amount of Helium in Moon : "))
perpower = int(input("Enter Power Generated Per Helium : "))
if(power * years < helium * perpower):   print("Funding Possible")
else : print("Funding Not Possible ")
