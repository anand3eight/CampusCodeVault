#CSV Books

import csv

def createfile() :
    with open('books.csv', 'w') as f:
        c = csv.writer(f)
        ls = ['Book_Name', 'Author', 'Price']
        c.writerow(ls)
        n = int(input('Enter Number of Books : '))
        bookls = []
        for i in range(n) :
            name = input('Enter Book Name : ')
            author = input('Enter Author Name : ')
            price = int(input('Enter Price : '))
            bookls.append([name, author, price])
        c.writerows(bookls)

def countrec(author) :
    with open('books.csv', 'r') as f :
        c = csv.reader(f)
        count = 0
        for i in c :
            if author in i :
                count += 1
        return count
print('Start')
createfile()
author = input('Enter Author Name to search : ')
print(countrec(author))

