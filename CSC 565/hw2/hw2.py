import socket
import sys
import datetime

CLIENT_PORT = 13500

SERVER_IP = "127.0.0.1"
SERVER_PORT = 12000

#extracts numeric values from two time objects and returns the difference
def timesub(a,b):
	a_list = str(a).split(':')
	b_list = str(b).split(':')
	return (float(a_list[2])-float(b_list[2]))

def main():
	
	# Create UDP socket
	sock = socket.socket(socket.AF_INET, socket.SOCK_DGRAM)
	server_address = (SERVER_IP, SERVER_PORT)
	
	# Send out 10 packets
	for i in range(10):
		base_time = datetime.datetime.now().time()#get start time
		sock.sendto(str(i+1)+" "+str(base_time),server_address)
		# wait for reply within a try-except statement
		try:
			sock.settimeout(1)
			data = sock.recv(1024)
			if data:
				print "Packet Contents: " + str(data)
				print "RTT:" + str(timesub(datetime.datetime.now().time(),base_time))
		except:
			print "Request timed out"

main();