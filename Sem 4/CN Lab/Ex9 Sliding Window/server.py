import socket as so

class Packet :
    def __init__(self, s, d) :
        self.seq_num = s
        self.data = d

    def encode(self):
        return f'{self.seq_num} {self.data}'.encode()

def receivePackets(sock, expected_packets) :
    packets = []
    expected_seq_num = 0
    while(expected_seq_num < expected_packets) :
        data, addr = sock.recvfrom(1024)
        msg = data.decode()
        print(f'Received Packet {msg.split()[0]}')
        if int(msg.split(" ")[0]) == expected_seq_num :
            packets.append(msg)
            expected_seq_num += 1
        if expected_seq_num % 3 == 0 :
            print(f'Sending ACK{expected_seq_num}')
            ackPacket = Packet(expected_seq_num, 'ACK')
            sock.sendto(ackPacket.encode(), addr)
            
if __name__ == '__main__' :    
    s = so.socket(so.AF_INET, so.SOCK_DGRAM)
    s.bind(('localhost', 8080))
    print('Socket created')
    expected_packets = 21
    receivePackets(s, expected_packets)
