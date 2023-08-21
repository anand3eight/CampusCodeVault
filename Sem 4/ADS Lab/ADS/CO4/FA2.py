# You are using Python
# Finite Automata String Matching
NOC = 256


def computeTF(pat, m, TF):
    lps = 0
    for x in range(NOC):
        TF[0][x] = 0
    TF[0][ord(pat[0])] = 1
    for i in range(1, m + 1):
        for x in range(NOC):
            TF[i][x] = TF[lps][x]
        if i < m:
            TF[i][ord(pat[i])] = i + 1
            lps = TF[lps][ord(pat[i])]


def searchFA(txt, pat):
    n = len(txt)
    m = len(pat)
    TF = [[0 for i in range(NOC)] for i in range(m + 1)]
    computeTF(pat, m, TF)
    for i in TF :
        print(i)
    j = 0
    for i in range(n):
        j = TF[j][ord(txt[i])]
        if j == m:
            print("Pattern found at index", i - m + 1)


txt = input()
pat = input()
searchFA(txt, pat)
