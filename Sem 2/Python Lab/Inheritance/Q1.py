#Person
import random

class PersonType :
    def __init__(self) :
        self.name = input("Enter Name : ")
        self.lastname = input("Enter Last Name : ")
        self.age = int(input("Enter Age : "))
        self.gender = input("Enter Gender : ")

class Reservation :
    def __init__(self):
        self.from_station = input("From  : ")
        self.to_station =   input("To    : ")
        self.amount_fare =  int(input("Price : "))
        
        self.seat_preference = input("Seat  : ")

class TicketBooking(PersonType, Reservation) :
    def __init__(self) :
        PersonType.__init__(self)
        Reservation.__init__(self)
    def availability(self) :
        self.av = random.randint(0,2)
        print(self.av)
    def discount(self) :
        if self.age > 60 :
            self.amount_fare *= 0.85
    def display(self) :
        if self.av != 0 :
            print(self.name, self.lastname, "\n"+ str(self.age), "\n"+ self.gender)
            print(self.from_station, self.to_station, "\n"+ str(self.amount_fare), "\n"+self.seat_preference)
ticket = TicketBooking()
ticket.availability()
ticket.discount()
ticket.display()

        
