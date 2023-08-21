#Standard Deck
import random

class std_deck :
    def __init__(self, d1, d2):
        self.d1 = d1
        self.d2 = d2
    def game(self):
        for i in range(10) :
            if self.d1[i] > self.d2[i] :
                self.d2.append(self.d1[i])
                self.d1[i] = 0
            elif self.d1[i] == self.d2[i] :
                self.d1[i] = 0
                self.d2[i] = 0
            else :
                self.d1.append(self.d2[i])
                self.d2[i] = 0
            if self.d1.count(0) == 5 :
                return 'You Win!'
            elif self.d2.count(0) == 5 :
                return 'You Lose'
        return 'Draw'

d1 = list(map(int, input('Enter Deck 1: ').strip().split()))[:5]
d2 = [random.randint(2, 11) for i in range(5)]
print('Deck 2 : ', d2)
s = std_deck(d1, d2)
print(s.game())