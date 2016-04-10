#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iostream>
#include <locale>


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
	char c;
  //bool valid = true;
  tempToken.value = s;
	for(unsigned int i=0; i<s.length();i++){
		c = s[i];
		if (std::isdigit(c) && tempToken.type != "NAME"){
			tempToken.setType("NUM");
		}
		else if (c == '+') {
			tempToken.setType("ADD");
			break;
		}
		else if (c == '-') {
			tempToken.setType("SUB");
			break;
		}
		else if (c == '*') {
			tempToken.setType("MULT");
			break;
		}
		else if (c == '/') {
			tempToken.setType("DIV");
			break;
		}
		else if (c == '=') {
			tempToken.setType("ASSIGN");
		}
		else if (std::isalpha(c)){
			tempToken.setType("NAME");
		}
	}
	lv.push_back(tempToken);
	s.clear();
}



std::vector<Token> tokenCreator(std::vector<char> input){
	std::vector<Token> tokens;
	std::string tempStr = "";
	for (unsigned int i = 0; i <= input.size(); i++) { // for each character in input
		char c = input[i];
		if (isspace(c)){	//if current character is whitespace, end token (if any) and keep going without adding to tempStr
			if (tempStr != "") {
				dumpToken(tokens,tempStr);
			}
		}else if (c=='+'||c=='-'||c=='*'||c=='/'||c=='='){//if current character is reserved, end token, create operator token
			if (tempStr != "") {
				dumpToken(tokens,tempStr);
			}
			tempStr += c;
			dumpToken(tokens,tempStr);
		}else{
			tempStr += c;//if current character is not whitespace or reserved symbol, append to tempStr
		}
	}
	if(tempStr != ""){
		tempStr.erase(tempStr.end()-1);
		dumpToken(tokens,tempStr);
	}
	return tokens;
}
