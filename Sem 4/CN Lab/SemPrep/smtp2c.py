import socket as so
import base64

if __name__ == '__main__' :
    c = so.socket(so.AF_INET, so.SOCK_STREAM)
    c.connect(('localhost', 8000))
    print('Connected to Server')
    msg = input('Enter Name, Email, Subject, Message : ')
    c.send(msg.encode())
    with open('test.jpeg', 'rb') as f :
        img = f.read()
    img = base64.b64encode(img)
    c.send(img)
    print('Sent to Server')
    c.close()