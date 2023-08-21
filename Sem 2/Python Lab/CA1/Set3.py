#Range Finder

n = int(input("Enter List Length : "))
ls = list(map(int, input("Enter : ").strip().split()))[:n]
for elmt in ls :
    ch = 0
    for i in range(n) :
        for j in range(n, i, -1) :
            mx = max(ls[i:j])
            if(mx == elmt) :
                print('[',i+1,',',j,']')
                ch = 1
                break
        if ch == 1 :
            break