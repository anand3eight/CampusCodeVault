#sliding window

#client:
import socket
win_size = 5
buff_size = 1024
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = ('localhost', 1100)
sock.connect(server_address)
msg=input("Enter Message :")
data =msg.encode() 
i=0
bytes_sent = 0
while bytes_sent < len(data):
    chunk_size = min(win_size, len(data) - bytes_sent)
    chunk = data[bytes_sent : bytes_sent + chunk_size]
    sock.sendall(chunk)
    ack = sock.recv(buff_size).decode()
    if(i%5==0):
        print(ack)
    bytes_sent += chunk_size
    i+=1
sock.close()




