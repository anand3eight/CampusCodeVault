import socket as so

class Packet :
    def __init__(self, s, d) :
        self.seq_num = s
        self.data = d

    def encode(self):
        return f'{self.seq_num} {self.data}'.encode()

def sendPackets(sock, packets, max_window_size) :
    up = packets.copy()
    next_seq_num, base, available_win = 0, 0, max_window_size
    while up :
        while next_seq_num < len(packets) and next_seq_num < base + available_win :
            print(f'Sending Packet {next_seq_num}')
            c.send(packets[next_seq_num].encode())
            next_seq_num += 1
            available_win = max_window_size - (next_seq_num - base)

        try :
            sock.settimeout(1)
            data, addr = sock.recvfrom(1024)
            m = data.decode()
            print(f'Received ACK {m.split()[0]}')
            ack = int(m.split(" ")[0])
            base = ack
            
            up = [packet for packet in up if packet.seq_num > ack]
        except so.timeout :
            next_seq_num = up[0].seq_num
                
    
if __name__ == '__main__' :
    c = so.socket(so.AF_INET, so.SOCK_DGRAM)
    c.connect(('localhost', 8080)) 
    print('Server Connected')
    packets = [Packet(i, f'Packet : {i}') for i in range(21)]
    window_size = 5
    sendPackets(c, packets, window_size)
    
