class manage:
    def __init__(self,psw):
        self.ps=psw
        self.psl=['abc','def','123']
    def set_psw(self):
        self.psl.append(self.ps)
        print('password set')
    def is_correct(self):
        if(self.ps not in self.psl):
            print(True)
            return 1
        else:
            print(False)
            return 0
psw=input('password :')
a=manage(psw)
ch=a.is_correct()
if(ch==1):
    a.set_psw()
    
        
