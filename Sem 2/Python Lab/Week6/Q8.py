#Top Two
import random


class card_deck :
    def __init__(self):
        self.hearts = [random.randint(2, 11) for i in range(5)]
        self.spades = [random.randint(2, 11) for i in range(5)]
        print('Hearts :' ,  self.hearts, '\nSpades : ', self.spades)
    def top2(self):
        self.hearts.sort(reverse=True)
        self.spades.sort(reverse=True)
        return self.hearts[:2] ,self.spades[:2]
c = card_deck()
print(c.top2())