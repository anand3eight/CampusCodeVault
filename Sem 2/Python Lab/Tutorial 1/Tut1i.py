#Absolute difference - Lists

n1  = int(input("Enter Length of List 1 : " ))
list1 = list(map(int, input("Enter List : ").strip().split()))[:n1]
n2  = int(input("Enter Length of List 2 : " ))
list2 = list(map(int, input("Enter List : ").strip().split()))[:n2]
abslist1 = list()
for i in range(n1-1) :
        elmt = abs(list1[i] - list1[i + 1])
        abslist1.append(elmt)
print(abslist1)
for i in abslist1 :
    mini = abs(abslist1[0] - list2[0])
    minielmt = list2[0]
    for j in list2 :
        elmt = abs(i - j)
        if(elmt < mini) :
            minielmt = j
    print(minielmt)
