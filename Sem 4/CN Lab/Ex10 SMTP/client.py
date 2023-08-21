import socket as so

if __name__ == '__main__' :
    c = so.socket()
    c.connect(('localhost',8000))
    print("Server Connected!")
    name = input("Enter name : ")
    c.send(bytes(name, 'utf-8'))
    to = input("Enter Recipient Mail : ")
    c.send(bytes(to, 'utf-8'))
    msg = input('Message : ')
    c.send(bytes(msg, 'utf-8'))

