#Number Generator

class Numbers : 
    def triangle(self, n) :
        print(int((n*(n+1))/2))
    def pentagon(self, n) :
        print(int((n*(3*n-1))/2))
    def hexagon(self, n) :
        print(int((n*(2*n-1))))
    def find_n(self, n, mark) :
        if mark in 'T' : self.triangle(n)
        elif mark in 'P' : self.pentagon(n)
        elif mark in 'H' : self.hexagon(n)
        else : print("Invalid Choice")

num = Numbers()
n = int(input("Enter N : "))
num.triangle(n)
num.pentagon(n)
num.hexagon(n)
n, mark = input("Enter N And Mark : ").split()
num.find_n(int(n), mark)
