#Havel Hakimi Algorithm
ls = list(map(int, input("Enter : ").strip().split()))[:10]
while(ls.count(0) != len(ls) ) :
    ls = [i for i in ls if i != 0]
    ls.sort(reverse = True)
    h = ls[0]
    ls = [i for i in ls if i != 0]
    if( h >= len(ls)) :
        print(False)
        break
    else :
        for i in range(len(ls)) :
            ls[i] -= 1
else :
    print(True)
        
