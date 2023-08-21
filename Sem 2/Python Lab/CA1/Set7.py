#String Split

def stsplit(st) :
    return st.split()
st = input("Enter : ")
st = st.replace('0', ' ')
ls = stsplit(st)
dc = {'First_Name' : ls[0], 'Last_Name' : ls[1], 'ID' : ls[2]}
print(dc)