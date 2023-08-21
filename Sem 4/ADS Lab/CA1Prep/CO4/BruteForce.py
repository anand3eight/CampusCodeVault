#BruteForce Algorithm

def bruteForce(text, pattern) :
    n = len(text)
    m = len(pattern)
    flag = 0
    for i in range(n-m+1) :
        j = 0
        while j < m and pattern[j] == text[i+j] :
            j += 1
            if j == m :
                print(f'Pattern Occurs in Shift {i}')
                flag = 1
    if flag == 0 :
        print('Pattern Not found')


text = "abcabaacabac"
pattern = "a"
bruteForce(text, pattern)
