#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iostream>


class Token {
public:
	Token(){}

	Token(std::string t, std::string v){ // Constructor.
		type = t;
		value = v;
	}

	std::string getValue() { return value; }
	std::string getType() { return type; }

	void setValue(std::string v) { value = v; }
	void setType(std::string t) { type = t; }

	friend void dumpToken(std::vector<Token> &lv, std::string &s);
	friend void tokenCreator();

	std::string type; // Token type (NAME, NUM, ADD, SUB, MULT, DIV, ASSIGN)
	std::string value; //Value of token in char/string format
};

//dumpToken method creates tokens from strings
void dumpToken (std::vector<Token> &lv, std::string &s){
	Token tempToken = Token();

	char c = s.back();

	tempToken.setValue(s);

	if (isalpha(c)) {
		tempToken.setType("NAME");
	}

	else if (isdigit(c)) {
		tempToken.setType("NUM");
	}

	else if (c == '+') {
		tempToken.setType("ADD");
	}
	else if (c == '-') {
		tempToken.setType("SUB");
	}
	else if (c == '*') {
		tempToken.setType("MULT");
	}
	else if (c == '/') {
		tempToken.setType("DIV");
	}
	else if (c == '=') {
		tempToken.setType("ASSIGN");
	}

	lv.push_back(tempToken);

	s.clear();
}



std::vector<std::vector<Token>> tokenCreator(std::vector<char> Input){
	std::vector<std::vector<Token>> tokenTable;
	std::string tempStr = "";
	std::vector<Token> line;
	int lineNum = 0;
	for (unsigned int i = 0; i <= Input.size(); i++) {
		char c = Input[i];
		std::cout << c << "\n";
		std::cout << tempStr.back() << "\n";
		if (isspace(c)) {	//Whitespace Check
			if (tempStr.empty() == false) {
				tempStr = "";
				//dumpToken(line, tempStr);
			}
		}
		else if (c == ';') { //Endline check
			tokenTable.push_back(line);
			lineNum++;	// this is how the tokenTable vector iterates
		}
		else if (c == '+') { //Addition operator check
			if (tempStr.empty() == false) {
				dumpToken(line, tempStr);
				tempStr+= '+';
				dumpToken(line, tempStr);
			}
		}
		else if (c == '-') { //Subtraction operator check
			if (tempStr.empty() == false) {
				dumpToken(line, tempStr);
				tempStr += '-';
				dumpToken(line, tempStr);
			}
		}
		else if (c == '/') { //Division operator check
			if (tempStr.empty() == false) {
				dumpToken(line, tempStr);
				tempStr += '/';
				dumpToken(line, tempStr);
			}
		}
		else if (c == '*') { //Multiplication operator check
			if (tempStr.empty() == false) {
				dumpToken(line, tempStr);
				tempStr += '*';
				dumpToken(line, tempStr);
			}
		}
		else if (c == '=') { //Assignment operator check
			if (tempStr.empty() == false) {
				dumpToken(line, tempStr);
				tempStr += '=';
				dumpToken(line, tempStr);
			}
		}
		else if (isdigit(c)) { //Checks string for mixing of numbers and digits
			if (!isdigit(tempStr.back())) {
				std::cout << "Error: you've got digits in your alphabet";
			}
			tempStr += c;
		}
		else if (isalpha(c)) { //Checks string for mixing of digits and numbers
			if (!isalpha(tempStr.back())) {
				std::cout << "Error: you've got letters in your Numbers";
			}
			tempStr += c;
		}
		else {
			tempStr += c; //if none of these add to existing string
		}
	}

	return tokenTable;
}
