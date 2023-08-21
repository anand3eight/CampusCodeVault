#Naive String Matching
def naiveMatch(text, pattern) :
    m = len(pattern)
    n = len(text)
    flag = 0
    for s in range(n-m+1) :
        if pattern == text[s:s+m] :
            print(f'Pattern Occurs in Shift {s}')
            flag = 1
    if flag == 0 :
        print('Pattern not Found')

text = "abcabaacabac"
pattern = "abac"
naiveMatch(text, pattern)