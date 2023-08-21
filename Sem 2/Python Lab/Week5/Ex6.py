#Sorted List Check

def is_sorted(ls):
    dup = ls.copy()
    ls.sort()
    if(dup == ls) :
        return True
    return False

n = int(input("Enter : "))
ls = list(map(int, input("Enter : ").strip().split()))[:n]
print(is_sorted(ls))
