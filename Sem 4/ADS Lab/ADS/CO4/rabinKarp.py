#RabinKarp String Matching Algorithm

def hash(key) :
    val = 0
    for i in key :
        val += ord(i)-ord('a')+1
    return val

def fpHash(key, n) :
    val = 0
    c = n-1
    for i in key :
        val += int((ord(i)-ord('a')+1)*pow(10, c))
        c -= 1
    return val

def normalHash(text, pattern) :
    pathash = hash(pattern)
    n = len(text)
    m = len(pattern)
    for i in range(n-m+1) :
        h = hash(text[i:i+m])
        if h == pathash :
            c = 0
            for j in range(m) :
                if text[i+j] == pattern[j] :
                    c += 1
                else :
                    break
            if c == m :
                print(f'Found at Shift{i}')

def rollingHash(text, pattern) :
    pathash = hash(pattern)
    n = len(text)
    m = len(pattern)
    for i in range(n - m + 1):
        if i == 0 :
            h = hash(text[i:i+m])
        else :
            h += (ord(text[i+m-1]) - ord(text[i-1]))
        if h == pathash:
            c = 0
            for j in range(m):
                if text[i + j] == pattern[j]:
                    c += 1
                else:
                    break
            if c == m:
                print(f'Found at Shift{i}')

def fingerPrint(text, pattern) :
    n = len(text)
    m = len(pattern)
    pathash = fpHash(pattern, m)
    for i in range(n-m+1) :
        h = fpHash(text[i:i+m], m)
        if h == pathash :
            print(f'Found at Shift{i}')

if __name__ == "__main__" :
    text = input("Text : ")
    pattern = input("Pattern : ")
    print('Rabin Karp - Normal Hash')
    normalHash(text, pattern)
    print('Rabin Karp - Rolling Hash')
    rollingHash(text, pattern)
    print('Rabin Karp - FingerPrint Hash Function')
    fingerPrint(text, pattern)