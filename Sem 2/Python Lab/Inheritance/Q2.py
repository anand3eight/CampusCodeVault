#Hotel

class Hotel :
    def __init__(self, hotelname = 'BINGO', city = 'COIMBATORE'):
        self.hotelname = hotelname
        self.city = city

class RestaurantMeal(Hotel) :
    def __init__(self, mealname, mealprice) :
        self.mname = mealname
        self.mprice = mealprice
        Hotel.__init__(self)
    def display(self):
        print('Hotel  :', self.hotelname)
        print('City   :', self.city)
        print('Meal   :', self.mname)
        print('Price  :',self.mprice)
        print()

class HotelService(Hotel) :
    def __init__(self, roomNo,  HotelService = 'Room Service', service_fee = 500) :
        self.hservice = HotelService
        self.service_fee = service_fee
        self.roomNo = roomNo
        Hotel.__init__(self)
    def display(self):
        print('Hotel  :', self.hotelname)
        print('City   :', self.city)
        print('Service:', self.hservice)
        print('Fee    :',self.service_fee)
        print('Room No:', self.roomNo)

rm = RestaurantMeal('Sandwich', 20)
hs = HotelService(input("Enter Room No : "))
rm.display()
hs.display()
