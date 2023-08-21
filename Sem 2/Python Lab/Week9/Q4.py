#Word Count

f = open('p042.txt', 'r')
dc = dict()
for word in f.read().split(',') :
    wordint = 0
    for letter in word :
        wordint += ord(letter)
    wordrem = wordint % 100
    if wordrem in dc :
        dc[wordrem].append(word)
    else :
        dc[wordrem] = list(word)
w = open('p042_summary.txt', 'w')
w.write(str(dc))

f.close()
w.close()