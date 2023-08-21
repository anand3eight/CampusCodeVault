#Credit Card Number

class CCchecker :
    def __init__(self, ccnum) :
        self.ccnum = ccnum
    def is_valid_format(self) :
        self.checkls = ['0','1','2','3','4','5','6','7','8','9', ' ']
        for i in self.ccnum :
            if i not in self.checkls :
                return 0
        
        return 1
    def is_valid_length(self) :
        if len(self.ccnum) == 16 + 3 :
            return 1
        else :
            return 0
    def is_valid_number(self):
        self.ccnum = self.ccnum
        self.num = []
        for i in self.ccnum :
            if i != ' ':
                self.num.append(int(i))
        print(self.num)
        self.dup = list()
        for i in range(0, 16) :
                print(i)
                if i % 2 == 0 :    
                    if int(self.num[i]) * 2 > 9 :  self.dup.append(int(self.num[i])*2 - 9)
                    else : self.dup.append(int(self.num[i]) * 2)
                else :
                    self.dup.append(self.num[i])
        print(self.dup)
        self.tot = sum(self.dup)
        if self.tot % 10 == 0 :
            print('Valid')
        else :
            print('Invalid')
                    
        
ccnum = input("Enter Number : ")
check = CCchecker(ccnum)
if check.is_valid_format() == 0 or check.is_valid_length() == 0 :
    print('Invalid')
else :
    check.is_valid_number()
    




              
