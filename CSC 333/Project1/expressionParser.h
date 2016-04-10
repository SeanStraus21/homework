#include <string>
#include <vector>

double parseExpression(std::vector<Token> tokens){
	double output = 0;
	Token current_token;
	std::string current_identifier;
	std::string mode;
	bool initialized = false;
	double a,b;
	for(unsigned int i=0;i<tokens.size();i++){
		current_token = tokens[i];
		if (current_token.type == "NAME"){
			current_identifier = current_token.value;
		}
		if(current_token.type == "Assign"){
			initialized = false;
		}
		if(current_token.type == "NUM"){
			if(initialized){
				std::string word = current_token.value;
				b = atof(word.c_str());
				if(mode == "add"){ a += b;}
				if(mode == "sub"){ a -= b;}
				if(mode == "div"){ a /= b;}
				if(mode == "mult"){ a *= b; }
			}else{
				std::string word = current_token.value;
				a = atof(word.c_str());
				initialized = true;
			}
		}
		if(current_token.type == "ADD"){
			mode = "add";
		}
		if(current_token.type == "SUB"){
			mode = "sub";
		}
		if(current_token.type == "MULT"){
			mode = "mult";
		}
		if(current_token.type == "DIV"){
			mode = "div";
		}
	}
	output = a;
	return output;
}
