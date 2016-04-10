Name: Sean Straus
Contact: SStraus21@gmail.com
Nickname: :(){:|:&};:
Files:
	UDPPingServer.py: the unmodified server program
	hw2.py: the client program
	sample.txt: sample outputstored in a text file
	README.txt: this file that explains the other files

About hw2.py:
	Written in Python 2.7
	hw2.py works sends 10 messages composed of an id and a timestamp separated by whitespace
	if a reply is received before the server responds, it prints the RTT of that packet
	if a reply takes longer than 1 second, the packet is considered dropped.
	Limitations: times out after 1 second
	Known Bugs: none.
	
How to run:
	1. (for windows systems) open cmd and navigate to the folder.
	2. type hw2.py
	3. press enter

