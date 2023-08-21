#Poker

class Poker_hand :
    def __init__(self, ls) :
        self.ls = ls
        self.dc = {'A' : '2',
                   '2' : '3',
                   '3' : '4',
                   '4' : '5',
                   '5' : '6',
                   '6' : '7',
                   '7' : '8',
                   '8' : '9',
                   '9' : '10',
                   '10' : 'J',
                   'J' : 'Q',
                   'Q' : 'K',
                   'K' : 'A'}
    def has_royal_flush(self) :
        if self.ls.count('A') == 3 :
            print('Has Royal Flush')
            for i in self.ls :
                if i == 'A' :
                    self.ls[self.ls.index(i)] = '0'
    def count_cards(self) :
        count = 0
        for i in self.ls :
            if self.dc[self.ls[i]] in self.ls :
                count += 1
            else :
                return count,i
    def has_three_of_a_kind(self) :
        for i in self.ls :
            if self.ls.count(i) == 3 :
                print('Has Three Of a Kind')
                for j in self.ls :
                    if j == i :
                        self.ls[self.ls.index(i)] = '0'
    def pair_count(self) :
        pair_count = 0
        for i in self.ls :
            if self.ls.count(i) == 2 :
                pair_count += 1
            return pair_count
    def best(self) :
        count = self.count_cards()
        if count == 6 :
            print('Full House')
        elif count == 5 :
            print('Has Straight Flush')
        elif count == 4 :
            print('Four of A Kind')
            
        
                
        
                        
            

pokerls = list(map(str, input("Enter Poker Card : ").strip().split()))[:7]
p = Poker_hand(pokerls)
