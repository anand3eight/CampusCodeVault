#Resistor Pattern

code = {'Black' : '0', 'Brown' : '1', 'Red' : '2' , 'Orange' : '3' , 'Yellow'  : '4' , 'Green' : '5', 'Blue' : '6' , 'Violet' : '7' , 'Grey' : '8'\}
inp1 = input("Enter Color 1 : ")
inp2 = input("Enter Color 2 : ")
inp3 = input("Enter Color 3 : ")
inp4 = input("Enter Color 4 : ")
print(code[inp1] + code[inp2] + code[inp3], 'x' ,10, '^' , code[inp4] , 'Ohms') 
