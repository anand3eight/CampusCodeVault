import socket as so
import smtplib

if __name__ == '__main__' :
    s = so.socket()
    mail = '21i205@psgtech.ac.in'
    pw = 'ccnnjiiguenmtnhe'
    s.bind(('localhost',8000))
    obj = smtplib.SMTP('smtp.gmail.com',587)
    obj.starttls()
    s.listen(1)
    while True:
        conn, addr = s.accept()
        name = conn.recv(1000).decode()
        print(f"Client connected {name}, {addr}")
        to = conn.recv(1000).decode()
        print(to)
        msg = conn.recv(1000).decode()
        print(msg)
        obj.login(mail, pw)
        obj.sendmail(mail, to, msg)
        print("Sent Mail!")
        break
    s.close()
    
