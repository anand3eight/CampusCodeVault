#Sliding Window - Client

import socket as so

if __name__ == '__main__' :
    c = so.socket(so.AF_INET, so.SOCK_DGRAM)
    c.connect(('localhost', 8080))
    print('Connected to Server')
    seq, base, WIN = 0, 0, 5
    av = WIN
    msg = ''
    while(1) :
        while(seq < base + av) :
            msg = input('Enter Message : ')
            p = f'{seq} {msg}'
            print(f"Sending Packet {seq}")
            seq += 1
            c.send(p.encode())
            av = WIN - (seq - base)

            try :
                c.settimeout(1)
                data, addr = c.recvfrom(1024)
                m = data.decode()
                print(f"Received {m}")
                rec = m.split()[0]
                m = int(m.split()[1])
                if(rec == 'NAK') :
                    seq = m
                elif(rec == 'ACK') :
                    base = m
            except so.timeout :
                if(seq > base + av) :
                    seq = base
            if(msg == 'exit') :
                break
        break
c.close()
