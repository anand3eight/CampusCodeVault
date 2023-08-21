#server:
import socket
listener = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
listener.setsockopt(socket.SOL_SOCKET, socket.SO_REUSEADDR, 1)
listener.bind(('localhost', 1100))
listener.listen(1)
print("Waiting\n")
connection, address = listener.accept()
print("Accepted connection from ",address[0],"at ", address[1], "\nData:\n")
i=0
while(True):
    try:
        data = connection.recv(1024).decode()
        if data!="":
            print(f"Frame {i}: {data}")
            print("Received packet ",i+1)
        i+=1
        if i%5==0:
            print("Sending ACK",i+1)
        connection.send(b'ack')
    except Exception:
        print("\n\nAll data received successfully")
        break
