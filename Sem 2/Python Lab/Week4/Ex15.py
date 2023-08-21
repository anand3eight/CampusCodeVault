#MadLibs
story = ''' Biology class was really boring today. We learned how to dissect today in class. I can't wait for
tomorrow's class! '''
cl = input("Enter Class Name  : ")
ad = input("Enter Adjective : ")
act = input("Enter an Activity : ")
res = story.replace('Biology', cl)
res = res.replace('boring', ad)
res = res.replace('dissect', act)
print(res)
