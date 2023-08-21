'''Create a class “Account” that maintains the userid and account number of each customer.
Create a class “CheckingAccount” with the functions showAccount, deposit  and
withdraw (double amount). If the balance amount after withdrawal is less than the minimum balance
then throw a user defined error InsufficientFundsException.
Use showAccount function to receive the userid and display the corresponding account number.
If the userid doesnot exist raise the
user defined error “NoUserId” which displays the message
“ class name: No such User id along with the user-id.'''

import sys

class InsufficientFundsException(Exception) :
    def __str__(self):
        return 'Insufficient Funds'
class NoUserIDerror(Exception) :
    def __str__(self):
        return 'User ID Unavailable'
customers = dict()
class account :
    def __init__(self):
        self.userid = int(input('Enter ID : '))
        self.accno = input('Enter Account No. : ')
        self.balance = 0
        customers[self.userid] = [self.accno, self.balance]

class checkingAccount() :
    def __init__(self, userid):
        self.userid = userid
    def showAccount(self):
        try :
                if self.userid not in customers :
                    raise NoUserIDerror
        except NoUserIDerror as e :
            print(e)
            sys.exit()
        else :
            print(customers[self.userid])

    def deposit(self):
         customers[self.userid][1] += int(input('Enter Deposit amount : '))

    def withdraw(self):
        try :
            amt = int(input('Enter Withdrawal Amount : '))
            if customers[self.userid][1] - amt < 0 :
                raise InsufficientFundsException
        except InsufficientFundsException as e :
            print(e)
        else :
            customers[self.userid][1] -= amt
            print('Withdrawal Successful')


a = account()
userid = int(input("Enter User ID : "))
c = checkingAccount(userid)
c.showAccount()
c.deposit()
c.withdraw()


