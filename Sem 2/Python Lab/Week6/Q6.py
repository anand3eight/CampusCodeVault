#Units Converter

class Converter :
    def __init__(self, val, unit) :
        self.val = val
        self.unit = unit
    def inch(self):
        return round(self.val/2.54, 2)
    def feet(self):
        return round(self.val/30.48, 2)
    def yard(self):
        return round(self.val/91.44, 2)
    def miles(self):
        return round(self.val/160934.4, 2)
    def kms(self):
        return round(self.val/100000, 2)
    def mts(self):
        return round(self.val/100, 2)
    def milli(self):
        return round(self.val*10, 2)
    def cms(self):
        return round(self.val, 2)
val, unit = map(str, input("Enter : ").strip().split())
val = int(val)
dc = {'in' : 2.54, 'ft' : 30.48 , 'yd' : 91.44 , 'mi' : 160934.4, 'km' : 100000, 'mt' : 100, 'cm' : 1, 'ml' : 0.1}
val *= dc[unit]
c = Converter(val, 'cm')
chdc = {1 : c.inch(),
2 : c.feet(),
3 : c.yard(),
4 : c.miles(),
5 : c.kms(),
6 : c.mts(),
7 : c.cms(),
8 : c.milli()}
ch = int(input("Enter Choice : "))
print(chdc[ch])




