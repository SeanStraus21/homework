/*=============================================================
	COURSE:	CSC-460, assignment 3
	PROGRAMMERS: 	Sean Straus (ss), Di Wu(dw)
	MODIFIED BY:
	LAST MODIFIED DATE:	03/15/2016
	DESCRIPTION:	Processes a text file and classifies each word as a string, float, or int
	NOTE:
	FILES:	classifier.cpp, classifier.h, main.cpp, makefile
	IDE/COMPILER/INTERPRETER:	C++11
	INSTRUCTION FOR COMPILATION AND EXECUTION:
	1. to COMPILE, run the following line
		$makefile
	2. to EXECUTE, run the following
		$ ./classifier

	Percentage of team members:
        Sean Straus
        Di Wu
=============================================================*/
#include <iostream>
#include <string>
#include <stdlib.h>
#include <fstream>
#include<sys/types.h>
#include <unistd.h>
#include "classifier.h"

using namespace std;

int main(int argc, char *argv[]){

    if (argc != 2){
        cout << "please run the program use this instruction: ./classifier [aFileName]" << endl;
        exit(0);
    }

    int pipe_ends[2];
    int float_count = 0;
    int int_count = 0;
    int string_count = 0;
    if(pipe(pipe_ends) < 0){
        cout << "failed to create pipe, program terminating" << endl;
        exit(0);
    }
    //open file
    string filename;
    ifstream file;
    filename = argv[1];
    filename = "/tmp/" + filename;
    file.open(filename);
    if (!file.is_open()){
        cout << "Could not open file " + filename +". program terminating." << endl;
        exit(0);
    }
    //read words from file
    string word;
    int child_count = 0;
    int child_id;
    while(file >> word){
        //create child processes to process words
        child_id = fork();
        if(child_id < 0){
            break;
        }
        child_count++;
        if (child_id == 0){
            child_report(word,pipe_ends[1],child_count);
            exit(0);
        }
    }
    if (child_count == 0){
        cout << "File is Empty, program terminating" << endl;
        exit(0);
    }
    file.close();

    while(true){
        child_count--;
        if(!read_report(string_count,float_count,int_count,pipe_ends[0])){
            break;
        }
        if(child_count == 0){
            break;
        }
    }
    cout << "**************************************" << endl;
    cout << "string count: " << string_count << endl;
    cout << "float count: " << float_count << endl;
    cout << "integer count: " << int_count << endl;
    cout << "**************************************" << endl;

    return 0;
}
