import socket as so
import smtplib

if __name__ == '__main__' :
    s = so.socket(so.AF_INET, so.SOCK_STREAM)
    s.bind(('localhost', 8000))
    print('Server Socket Created')
    obj = smtplib.SMTP('smtp.gmail.com', 587)
    obj.starttls()
    s.listen(1)
    mail = '21i205@psgtech.ac.in'
    pswd = 'ccnnjiiguenmtnhe'
    conn, addr = s.accept()
    data = conn.recv(1024).decode()
    name, to, msg = map(str, data.split())
    print(f'Name : {name} \nTo : {to} \nMessage : {msg}')
    obj.login(mail, pswd)
    obj.sendmail(mail, to, msg)
    print('Sent Mail!')