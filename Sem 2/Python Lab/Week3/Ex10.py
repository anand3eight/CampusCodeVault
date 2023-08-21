#Histogram

word1 = input("Enter : ")
word2 = input("Enter : ")
dict1 = dict()
dict2 = dict()
for i in word1 :
    if i in dict1 :
        dict1[i] += 1
    else :
        dict1[i] = 1
for i in word2 :
    if i in dict2 :
        dict2[i] += 1
    else :
        dict2[i] = 1
#Merging Dictionaries
for i in dict2.keys() :
    if i in dict1.keys() :
        dict1[i] += dict2[i]
    else :
        dict1[i] = dict2[i]
print(dict1)