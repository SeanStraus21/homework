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
#include <string>
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include<sys/types.h>
#include <cstring>
#include <unistd.h>
using namespace std;

string classify(string s){
    string output = "i";
    char c;
    for(unsigned int i=0;i<s.length();i++){
        c = s[i];
        if (!isdigit(c)){
            if(c == '.'){
                if (output == "i"){
                    output = "f";
                }else{
                    output = "s";
                    break;
                }
            }else{
                output = "s";
                break;
            }
        }
    }
    return output;
}

void child_report(string s,int pe, int child_count){
    string id = to_string(getpid());
    string result = classify(s);
    string buffer = id+result+s;
    unsigned int position = 0;
    unsigned int n = buffer.length();
    unsigned char bytes[4];
    unsigned char buf[256] = {' '};
    bytes[0] = (n >> 24) & 0xFF;
    bytes[1] = (n >> 16) & 0xFF;
    bytes[2] = (n >> 8) & 0xFF;
    bytes[3] = n & 0xFF;
    for(unsigned int i=0;i<4;i++){
        buf[position] = bytes[i];
        position++;
    }
    for(unsigned int i=0;i<248;i++){
        if(i<n){
            buf[position] = buffer[i];
        }
        position++;
    }
    bytes[0] = (child_count >> 24) & 0xFF;
    bytes[1] = (child_count >> 16) & 0xFF;
    bytes[2] = (child_count >> 8) & 0xFF;
    bytes[3] = child_count & 0xFF;
    for(unsigned int i=0;i<4;i++){
        buf[position] = bytes[i];
        position++;
    }
    write(pe,buf,256);
}

bool read_report(int &string_count,int &float_count,int &int_count,int pe){
    unsigned char x[256] = {' '};
    unsigned char y[2] = {' '};
    unsigned char z[256] = {' '};
    unsigned int n,d;
    unsigned char bytes[4];
    unsigned char c;
    bool output = true;
    unsigned char s[248] = {' '};
    int x_counter = 0;
    int z_counter = 0;
    int size = read(pe,bytes,4);
    if(size == 0){return false;}
    n = bytes[0] + bytes[1] + bytes[2] + bytes[3];
    size = read(pe,s,248);
    size = read(pe,bytes,4);
    d = bytes[0] + bytes[1] + bytes[2] + bytes[3];
    for(unsigned int i=0;i<n;i++){
        c = s[i];
        if(isalpha(c)){
            y[0] = c;
            unsigned int k = i+1;
            for(unsigned int j = k;j<n;j++){
                c = s[j];
                z[z_counter] = c;
                z_counter++;
            }
            break;
        }else{
            x[x_counter] = c;
            x_counter++;
        }
    }
    if (y[0] == 's'){
        string_count++;
    }else if (y[0] == 'i'){
        float_count++;
    }else{
        int_count++;
    }
    cout << endl;
    cout << "--------------------------------------" << endl;
    cout << "child ID: " << x << endl;
    cout << "Type: " << y << endl;
    cout << "Word: " << z << endl;
    cout << "child created when i = " << d << endl;
    cout << "--------------------------------------" << endl;
    cout << endl;
    return output;
}
