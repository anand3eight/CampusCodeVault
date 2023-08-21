#Investment

class Investment :
    def __init__(self):
        self.invt, self.ct = map(int, input("Enter Investment and Current Value : ").split())
        self.pft = self.ct - self.invt
        self.perpft = self.pft / self.invt

class House :
    def __init__(self):
        self.ad = input("Enter address : ")
        self.ft = input("Enter sqft : ")

class HTIAI(Investment,House):
    def __init__(self):
        Investment.__init__(self)
        House.__init__(self)
    def display(self):
        print(self.invt, self.ct,self.pft,round(self.perpft,2),self.ad,self.ft)

h=HTIAI()        
h.display()
