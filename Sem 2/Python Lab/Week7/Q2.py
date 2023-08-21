#Smartest

class overflowError(Exception) :
    def __str__(self) :
        return 'Value Above 100'

class underflowError(Exception) :
    def __str__(self) :
        return 'Value Below 0'
class smartList :
    def __init__(self) :
        self.stack = [1,2,3]
    def push(self, elmt) :
        try :
            if elmt > 100 :
                raise overflowError
        except overflowError as e :
            print(e)
        else :
            self.stack.append(elmt)
            print('Appended Successfully')
    def pop(self) :
        try :
            if self.stack[-1] < 0 :
                raise underflowError
        except underflowError as e :
                print(e)
        else :
                self.stack.pop(-1)
                print('Deleted Succesfully')
    def size(self) :
        print(len(self.stack))
    def removeGreater(self, elmt) :
        dup = self.stack
        for i in dup :
            if i > elmt :
                self.stack.remove(i)
        print('Removed successfully')
    def displayStack(self) :
        print(self.stack)
    def displayOrdered(self) :
        self.dup = self.stack
        self.dup.sort()
        print(self.dup)
a = smartList()
print('1 : Push \n2 : Pop \n3 : Size \n4 : Remove \n5 : Display \n6 : Ordered Display \n0 : Exit')
ch = int(input('Enter Choice : '))
while(ch != 0) :
    if(ch == 1) :
        elmt = int(input("Enter Element : "))   
        a.push(elmt)
    elif(ch == 2) :
        a.pop()
    elif(ch == 3) :
        a.size()
    elif(ch == 4) :
        elmt = int(input("Enter Element : "))
        a.removeGreater(elmt)
    if(ch == 5) :
        a.displayStack()
    if(ch == 6) :
        a.displayOrdered()
    ch = int(input('Enter Choice : '))
    
