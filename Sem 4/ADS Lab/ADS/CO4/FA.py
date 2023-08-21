#String Matching using Finite Automata

def computeTF(pattern, m) :
    lps = 0
    TF = [[0 for i in range(256)] for i in range(m+1)]
    TF[0][ord(pattern[0])] = 1
    for i in range(1,m+1) :
        for j in range(256) :
            TF[i][j] = TF[lps][j]
        if i < m :
            TF[i][ord(pattern[i])] = i+1
            lps = TF[lps][ord(pattern[i])]
    return TF
def FA(text, pattern) :
    n = len(text)
    m = len(pattern)
    TF = computeTF(pattern, m)
    j = 0
    for i in range(n) :
        j = TF[j][ord(text[i])]
        if j == m :
            print(f'Found at Shift{i-m+1}')
            break
if __name__ == "__main__" :
    text = input("Text : ")
    pattern = input("Pattern : ")
    FA(text, pattern)