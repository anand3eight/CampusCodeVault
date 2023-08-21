n = int(input("Enter Number of email addresses : "))
emails = []
for i in range(n) :
    email = input("Enter Email : ")
    emails.append(email)
ch = 1
for email in emails :
    if "@prof" in email :
        ch = 0
        print("Professor Emails are there too" )
        break
if(ch == 1) : print("Only Student Emails " )
