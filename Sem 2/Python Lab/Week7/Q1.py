#Password Check

def chk(a, b) :
    for i in a :
        if i in b :
            return 1
    return 0
class invalidUserError(Exception) :
    def __str__(self):
        return 'User ID Unavailable'
class check() :
    def __init__(self) :
        self.dc = {'asv' : 'Rev@nthmy3F'}
    def validpswd(self, userid, pswd) :
        self.alph = [chr(i) for i in range(65,91)]
        self.dig = [str(i) for i in range(0, 10)]
        self.sym = ['#', '$', '@', '%', '!', '^', '&', '*']
        self.lt = len(pswd)

        if self.lt > 10 and chk(pswd, self.alph) == 1 and chk(pswd, self.dig) == 1 and chk(pswd, self.sym) == 1 :
            self.dc[userid] = pswd
        else :
            print('Invalid Password')
    def modify_user(self, userid) :
        try :
            if userid not in self.dc :
                raise invalidUserError()
        except invalidUserError as e:
            print(e)
        else :
            self.ps = input("Enter Password : ")
            self.validpswd(userid, ps)
    def addUser(self, userid) :
        self.userid = userid
        self.pswd = input("Enter Password : ")
        self.validpswd(self.userid, self.pswd)
    def findPassword(self, userid) :
        try :
            print(self.dc[userid])
        except KeyError as e :
            print("User Details unavailable")

c = check()

print('1 : Modify \n2 : Find Password \n3 : Add \n0 : Exit')
ch = int(input())
while(ch != 0) :
    userid = input("Enter UserID : ")
    if ch == 1 :
       c.modify_user(userid)
    elif ch == 2 :
        c.findPassword(userid)
    elif ch == 3 :
        c.addUser(userid)
    else :
        print('Invalid Choice')
    ch = int(input("Enter Choice : "))
