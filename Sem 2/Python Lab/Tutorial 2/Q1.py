#Alien Collision
class Alien :
    def __init__(self, x, y) :
        self.x = x
        self.y = y
        self.health = 3
    def hit(self) :
        self.health -= 1
    def Is_Alive(self) :
        if self.health <= 0 :
            print('Game Over')
        else :
            print("Health : ", self.health)
    def teleport(self, nx, ny) :
        self.x = nx
        self.y = ny
    def Collision_detection(self, x, y) :
         if self.x - x < 3 or self.y - y < 3 :
             self.hit()
             self.Is_Alive()
    def displayCd(self) :
        print(self.x, self.y)


x,y = map(int, input("Enter Co-Ordinates : ").split())
a = Alien(x,y)
count = 0
countls = list()
ch = 1
while(ch != 0) :
    obx, oby = map(int,input("Enter Object Co-ordinates : ").split())
    a.Collision_detection(obx, oby)
    count += 1
    countls.append((obx,oby))
    ch = int(input("To End : Press 0 "))
print(count)
print(countls)
