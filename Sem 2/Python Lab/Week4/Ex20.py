#USTime Zone
time = input("Enter Time - HH:MMam/pm : ")
if(time[5:] in 'pm' ) : time = str(int(time[:2]) + 12) + time[2:]
st = input("Enter Starting TimeZone : ")
end = input("Enter Ending Timezone : ")
d = {'Pacific' : 1, 'Mountain' : 2, 'Central' : 3, 'Eastern' : 4}
if(d[end] > d[st]) :
    endtime = str((int(time[:2]) + abs((d[st] - d[end])))) + time[2:5]
else :
    endtime = str((int(time[:2]) - abs(d[st] - d[end]))) + time[2:5]
if(int(endtime[:2]) > 12) : endtime = str(int(endtime[:2]) - 12) + time[2:5] + 'pm'
else : endtime += 'am'
print(endtime)