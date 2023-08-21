#Baum-Sweet Sequence

n = input("Enter Number : ")
for i in range(1, int(n) + 1) :
    bn = str(bin(i)).replace('0b', '')
    if bn.count('0') == 0 :
        print('b_'+str(i), '=', 1)
        continue
    ls = list(range(1, len(bn)))
    ls.reverse()
    for j in ls :
        if '0'* j in bn and j % 2 == 0:
            print('b_'+str(i), '=', 1)
        else :
            print('b_'+str(i), '=', 0)
        break
