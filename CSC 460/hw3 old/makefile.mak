#	COURSE:	CSC-460, assignment 3
#	PROGRAMMERS: 	Sean Straus (ss), Di Wu(dw)
#	MODIFIED BY:
#	LAST MODIFIED DATE:	03/15/2016
#	DESCRIPTION: 	A makefile for classifier
#	NOTE:
#	FILES:	classifier.cpp, main.cpp, classifier.h makefile
#	IDE/COMPILER/INTERPRETER:	GNU g++
#	INSTRUCTION FOR COMPILATION AND EXECUTION:
#	1. to COMPILE, run the following line
#		$make
#	2. to EXECUTE, run the following
#		$ ./classifier
#
#	Percentage of team members:


CC = c++11

classifier: main.cpp classifier.o classifier.h
	$(CC) main.cpp classifier.o -o classifier

classifier.o: classifier.cpp
	$(CC) -c classifier.cpp -o classifier.o
