#Details

class Person :
    def __init__(self) :
        self.fname, self.lname = map(str, input("Enter Name : ").split())
class Address :
    def __init__(self) :
        self.address, self.city, self.state, self.pincode = map(str, input("Enter Address : ").split(','))
class Date :
    def __init__(self) :
        self.day, self.month, self.year = map(str, input("Enter DOB : ").split('/'))

class AboutPerson(Person, Address, Date) :
    def __init__(self) :
        Person.__init__(self)
        Address.__init__(self)
        Date.__init__(self)
    def display(self) :
        print("Name :", self.fname, self.lname)
        print("Address :", self.address, self.city, self.state, self.pincode)
        print("DOB :", self.day, self.month, self.year)

p = AboutPerson()
p.display()
        
    
