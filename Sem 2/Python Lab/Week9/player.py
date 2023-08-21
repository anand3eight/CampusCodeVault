#Module Player

class player() :
    def __init__(self):
        self.name = input('Enter Name : ')
        self.score = int(input('Enter Player Score : '))
        self.rank = int(input('Enter Rank : '))
        self.country = input('Enter Country : ')
        self.role = input('Enter Role : ')
        self.playerls = [self.name, self.score, self.rank, self.country, self.role]
def createplayer() :
    count = int(input('Enter Number of Players : '))
    players = list()
    for i in range(count) :
        c = player()
        players.append(c.playerls)
    return players

if __name__ == '__main__' :
    createplayer()
