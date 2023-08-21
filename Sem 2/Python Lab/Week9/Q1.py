# To change m - x and x - m

f1 = open('sample.txt', 'r')
f2 = open('samplenew.txt', 'w')
for word in f1.read().split():
    newword = word.replace('x', '*')
    newword = newword.replace('m', 'x')
    newword = newword.replace('*', 'm')
    f2.write(newword + ' ')
print('Completed')
f1.close()
f2.close()
