letter = '''Dear Name,
I am pleased to offer you our new Platinum Plus Rewards
card at a special introductory APR of 47.99%. Firstname,
an offer like this does not come along every day, so I
urge you to call now toll-free at 1-800-314-1592. We
cannot offer such a low rate for long, Firstname, so call
right away.
'''
name = input("Enter Name : ")
reslet = letter.replace('Name', name)
reslet = reslet.replace("Firstname", name[:name.index(' ')])
print(reslet)
