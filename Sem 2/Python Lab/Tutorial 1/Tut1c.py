# Birthday Entry

n = int(input("Enter Number of Birthdays : "))
febCount = 0
day25Count = 0
for i in range(n) :
    inp = input("Enter MM/DD : ")
    mon, day = inp.split('/')
    if(mon == '02') :
        febCount += 1
    if(day == '25' ) :
        day25Count += 1
print(febCount, day25Count)
