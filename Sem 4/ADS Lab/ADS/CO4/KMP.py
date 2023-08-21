#KMP String Matching

def LPS(pat, m) :
    i, l = 1, 0
    lps = [0] * m
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
    return lps

def KMP(text, pattern) :
    n = len(text)
    m = len(pattern)
    lps = LPS(pattern, m)
    i, j = 0, 0
    while i <= n-m+j :
        if text[i] == pattern[j] :
            i += 1
            j += 1
            if j == m :
                print(f'Found at Shift{i-j}')
                j = lps[j-1]
        else :
            if j != 0 :
                j = lps[j-1]
            else :
                i += 1

if __name__ == "__main__" :
    text = input("Text : ")
    pattern = input("Pattern : ")
    KMP(text, pattern)