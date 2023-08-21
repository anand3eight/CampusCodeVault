#Robot Mines

st = '''++++++++++++++000000000000+0000000*000++00000000000++00000000*00++00000000000+M00000000000++++++++++++++'''
print(len(st))
dc = {'N' : -13, 'S' : +13, 'E' : +1 , 'W' : -1}
s = input("Enter Path : ")
ch = 0
chk = 1
ind = st.index('M')
for i in s :
    print(ind)
    if i == 'I': ch = 1
    elif i == 'O' : ch = 0
    elif ch != 0 :
        ind += dc[i]
        if st[ind] == '+' : ind -= dc[i]
        elif st[ind] == '*' :
            print('Trapped')
            chk = 0
            break
        elif ind == 24 :
            print('Success')
            chk = 0
            break
if chk != 0 :
    print('Not Reached')


