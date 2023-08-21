#Sliding Window - Server
import socket as so

if __name__ == '__main__' :
    s = so.socket(so.AF_INET, so.SOCK_DGRAM)
    s.bind(('localhost', 8080))
    print('Server Socket Created')
    exp, msg = 0, ''
    while(msg != 'exit') :
        data, addr = s.recvfrom(1024)
        data = data.decode()
        seq = int(data.split(' ')[0])
        msg = str(data.split(' ')[1])
        if(exp == seq) :
            print(f'Received Packet {seq} with Message : {msg}')
            exp += 1
            if (exp % 3 == 0 or msg == 'exit') :
                print(f'Sending ACK {exp}')
                s.sendto(f'ACK {exp}'.encode(), addr)
        else :
            print(f'Packet not in Order')
            print(f'Sending NAK {exp}')
            s.sendto(f'NAK {exp}'.encode(), addr)
s.close()


    