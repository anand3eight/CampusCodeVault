#Queens in a Board


ls = list(map(int, input("Enter : ").strip().split()))[:6]
ch = 1
if len(ls) < 6 :
        ch = 0
        print(False)
for i in ls :
        if(ls.count(i) == 1) :
            continue
        else :
            print(False)
            ch = 0
            break
if ch!= 0 :
         for i in range(len(ls)) :
             for j in range(i + 1, len(ls)) :
                 a = abs(i - j)
                 b = abs(ls[i] - ls[j])
                 if(a == b) :
                     ch = 0
                     print(False)
                     break
if ch != 0 :
        print(True)
