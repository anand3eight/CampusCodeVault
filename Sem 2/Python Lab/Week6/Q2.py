class prcal:
    def __init__(self,name,q,p):
        self.name=name
        self.quantity=q
        self.price=p
    def get_price(self):
        if(self.quantity>10):
            self.tot=0.9*self.quantity*self.price
        elif(self.quantity>100):
            self.tot=0.8*self.quantity*self.price
        else:
            self.tot=self.quantity*self.price
    def purchase_decission(self):
        print('total = ',self.tot)
        
name=input('name of prodeuct')
q=int(input('quantity'))
p=float(input('price'))
a=prcal(name,q,p)
a.get_price()
ch=input('Confirm purchase')
if(ch in 'yes'):
    a.purchase_decission()
