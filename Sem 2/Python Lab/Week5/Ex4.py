#Histogram Function

def histogram(ls) :
    dc = dict()
    for i in ls :
        if i not in dc :
            dc[i] = 1
        else :
            dc[i] += 1
    return dc

n = int(input("Enter Length of List : "))
ls = list(map(int, input("Enter : ").strip().split()))[:n]
print(histogram(ls))