#Brute Force /Naive String Matching

def bruteForce(txt, pat) :
    for i in range(len(txt)-len(pat)+1) :
        if txt[i] == pat[0] :
            c = 1
            for j in range(1, len(pat)) :
                if(txt[i+j] == pat[j]) :
                    c += 1
                else :
                    break
            if c == len(pat) :
                print(f'Found at Shift{i}')
if __name__ == "__main__" :
    text = input("Text : ")
    pattern = input("Pattern : ")
    bruteForce(text, pattern)
