import socket as so

if __name__ == '__main__' :
    c = so.socket(so.AF_INET, so.SOCK_STREAM)
    c.connect(('localhost', 8000))
    print('Connected to Server')
    msg = input('Enter Name, Email, Message : ')
    c.send(msg.encode())
    print('Sent to Server')