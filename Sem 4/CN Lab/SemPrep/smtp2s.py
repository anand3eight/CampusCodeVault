import socket as so
import smtplib
import base64
from email.mime.text import MIMEText
from email.mime.multipart import MIMEMultipart
from email.mime.image import MIMEImage

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
    name, to, sub, msg = map(str, data.split())
    print(f'Name : {name} \nTo : {to} \nSubject : {sub} \nMessage : {msg}')
    message = MIMEMultipart()
    message.attach(MIMEText(msg))
    message['Subject'] = sub
    data = conn.recv(5000)
    data = base64.b64decode(data)
    message.attach(MIMEImage(data, name='test.jpeg', _subtype = 'jpeg'))
    obj.login(mail, pswd)
    obj.sendmail(mail, to, message.as_string())
    print('Sent Mail!')
    obj.quit()
    s.close()