#To-Do List

class toDoList :
    def __init__(self) :
        self.itemls = list()
    def add_item(self, item) :
        self.itemls.append(item)
    def delete_item(self, ditem) :
        if item in self.itemls :
            self.itemls.remove(item)
        else :
            print("No Item Available ")
    def printLs(self) :
        print(self.itemls)
print('1: Add \n2: Delete \n3:Print')
test = 1
td = toDoList()
while(test != 0) :
    ch = int(input("Enter Your Choice : "))
    if ch == 1 :
            item = input("Enter Item : ")
            td.add_item(item)
    elif ch == 2 :
            item = input("Enter Item : ")
            td.delete_item(item)
    elif ch == 3 :
            td.printLs()
            test = 0
    else :
            print("Enter Valid Choice")
