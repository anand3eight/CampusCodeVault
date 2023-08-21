#Anagram Generator

import itertools
def anagram(st) :
    for i in itertools.permutations(st) :
        print(i)
    return

st = input("Enter : ")
anagram(st)