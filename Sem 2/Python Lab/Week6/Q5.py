#WordPlay

        
class wordplay :
    def __init__(self, wdls) :
        self.wdls = wdls
    def length(self) :
        print("Length : ", end = ' ') 
        for wd in self.wdls :
            print(len(wd), end = ' ')
        print()
    def start_s(self) :
            print('Words that start with S : ', end = ' ')
            for wd in self.wdls :
                if 's' in wd and wd.index('s') == 0 :
                    print(wd, end = ' ')
            print()
    def end_s(self) :
            print('Words that end with S : ', end = ' ')
            for wd in self.wdls :
                if 's' in wd and wd[-1: -len(wd)-1:-1].index('s') == 0 :
                    print(wd, end = ' ')
            print()
    def palindrome(self) :
        print('Palindrome Words : ', end = ' ')
        for wd in self.wdls :
            nwd = wd[-1:-len(wd)-1:-1]
            if nwd == wd :
                print(wd, end = ' ')
        print()
    def only_l(self) :
        print('Words with L :', end = ' ')
        for wd in self.wdls :
            if 'l' in wd :
                print(wd,end = ' ')
        print()
    def avoids_l(self) :
        print('Words without L :', end = ' ')
        for wd in self.wdls :
            if 'l' not in wd :
                print(wd,end = ' ')
        print()
n = int(input("Enter Number of Words : "))
wd = list(map(str, input("Enter Word : ").strip().split()))[:n]
a = wordplay(wd)
a.length()
a.start_s()
a.end_s()
a.palindrome()
a.only_l()
a.avoids_l()

