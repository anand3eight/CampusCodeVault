#Rabin Karp Algorithm

def hashFunction(word) :
    st = ord('A') - 1 #65 - 1 = 64 -> A = 1
    hash = 0
    for i in word :
        hash += ord(i) - st
    return hash


def rabinKarp(text, pattern) :
    n = len(text)
    m = len(pattern)
    hpattern = hashFunction(pattern)
    flag = 0
    for i in range(n-m+1) :
        hs = hashFunction(text[i:i+m])
        if hs == hpattern :
            if text[i:i+m] == pattern :
                print(f'Pattern Occurs in Shift {i}')
                flag = 1
    if flag == 0 :
        print('Pattern Not found')


text = "abcabaacabac"
pattern = "abac"
rabinKarp(text, pattern)