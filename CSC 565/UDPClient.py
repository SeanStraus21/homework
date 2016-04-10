import socket
import sys

SERVER_IP = "127.0.0.1"
CLIENT_PORT = 13500
SERVER_PORT = 13501
LISTEN_PORT = 13502

def main():
	amount = input("Enter Starting Amount (unformatted integer): ")
	years = input("Enter Number of Years: ")
	rate = input("Enter Interest Rate (floating point decimal between 100 and 0): ")

	# Create UDP socket
	sock = socket.socket(socket.AF_INET, socket.SOCK_STREAM)
	server_address = (SERVER_IP, SERVER_PORT)
	print 'connecting to %s port %s' % server_address

	try:
		print 'Sending Data'
		sock.sendto(str(amount) + " " + str(years) + " " + str(rate),SERVER_IP)

		# Wait for response
		storage = ""
		while True:
			data = sock.recv(16)
			if data:
				storage += str(data)
				break
		data_list = storage.split()
		print "Monthly Payment: " + data_list[0]
		print "Total Payment: " + data_list[1]
		

	finally:
		print >>sys.stderr, 'closing socket'
		sock.close()

main();