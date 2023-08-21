# You are using Python
#KMP String Matching
def LPS(pat, m, lps) :
    i, l = 1, 0
    lps[0] = 0
    while i < m :
        if pat[i] == pat[l] :
            l += 1
            lps[i] = l
            i += 1
        else :
            if l != 0 :
                l = lps[l-1]
            else :
                lps[i] = 0
                i += 1
            
def KMP(txt, pat) :
    n, m = len(txt), len(pat)
    lps = [0] * m
    LPS(pat, m, lps)
    i, j = 0, 0
    while i <= n-m+j : 
        if txt[i] == pat[j] :
            i += 1
            j += 1
        if j == m :
            print("Found pattern at index ", i-j)
            j = lps[j-1]
        elif txt[i] != pat[j] :
            if j != 0 :
                j = lps[j-1]
            else :
                i += 1
                
txt = input()
pat = input()
KMP(txt, pat)