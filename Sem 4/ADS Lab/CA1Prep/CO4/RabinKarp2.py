#Rabin Karp Algorithm Ver2

d = 256

def hashFun(chr) :
    return ord(chr) - ord('A') + 1

def rabinKarp(text, pattern, q) :
    n = len(text)
    m = len(pattern)
    hpattern = 0
    htext = 0
    flag = 0
    h = 1 #Hash Value for Rabin Karp
    for i in range(1, m) : #Returns h = pow(d, m-1)
        h = (h*d) % q

    for i in range(m) : #Calcuates Hash of pattern and Text
        hpattern = (d*hpattern + hashFun(pattern[i])) % q
        htext = (d*htext + hashFun(text[i]))% q

    for i in range(0, n-m+1):
        if htext == hpattern :
            j = 0
            while j < m and text[i+j] == pattern[j] :
                j += 1
                if j == m :
                    print(f'Pattern Occurs in Shift {i}')
                    flag = 1

        if i < n-m :
            htext = (d * (htext - hashFun(text[i]) * h) + hashFun(text[i+m])) % q

        if htext < 0 :
            htext += q

    if flag == 0 :
        print('Pattern Not found')


text = "abcabaacabac"
pattern = "aba"
q = 1 #Prime Number
rabinKarp(text, pattern, q)