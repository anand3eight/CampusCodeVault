import math
class investment:
    def __init__(self,p,i,n):
        self.pr=p
        self.int=i
        self.years=n
    def interest(self):
        self.amt=self.pr*pow(1+self.int,n)
    def __str__(self):
        print('principal = ',self.pr,' rate = ',self.int,'amount = ',self.amt)
p=int(input('principal'))
i=float(input('interest'))
n=int(input('years'))
a=investment(p,i,n)
a.interest()
a.__str__()
