import socket
import sys

SERVER_IP = "127.0.0.1"
CLIENT_PORT = 13500
SERVER_PORT = 13501
LISTEN_PORT = 13502

def monthly_payment(L, Y, R):
	N = 12*Y #N = number of payments
	return (L*R)/(1-pow(1/(1+R),N))
	
def total_payment(L, Y, R):
	return monthly_payment(L, Y, R)*Y

# Create TCP/IP socket and bind it to the port
sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
server_address = (SERVER_IP, SERVER_PORT)
print 'starting up on %s port %s' % server_address
sock.bind(server_address)
# Listen for incoming connections
sock.listen(1)

while True:
	# Wait for messages
	data,client_address = sock.recv(16)
	print 'message from', client_address
	print 'Processing ' + str(data)
	storage = str(data).split()
	data = str(monthly_payment(float(storage[0]),float(storage[1]),float(storage[2])))
	data += " "
	data += str(total_payment(float(storage[0]),float(storage[1]),float(storage[2])))
	s.sendto(data,client_address);
	print 'message sent'
	
	finally:
		# End connection and close socket
		connection.close()