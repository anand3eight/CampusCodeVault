import player
import csv

def hb(players) :
    countries = ['AUS', 'IND', 'WI']
    with open('scores.csv' , 'w') as f:
        c = csv.writer(f)
        maxscore = 0
        index = 0
        for country in countries :
            for row in players :
                if country in row :
                    if row[1] > maxscore :
                       index = players.index(row)
            c.writerow(players[index])
        print('Completed')

def hr(players) :
    roles = ['BAT', 'AR', 'BW']
    with open('ranks.csv' , 'w') as f:
        c = csv.writer(f)
        index = 0
        for role in roles :
            for row in players :
                if role in row :
                    if row[2] == 1 :
                       index = players.index(row)
                        break
            c.writerow(players[index])
        print('Completed')
hr(player.createplayer())
hb(player.createplayer())
