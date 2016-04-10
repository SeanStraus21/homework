#include <string>
#include <vector>
#include <cstring>
#include <cctype>
#include <cstdlib>
#include <iostream>


bool SemanticAnalysis(std::vector<std::vector<Token>>);

bool is_operator(std::string s){
	return (s == "ADD" || s == "SUB" || s == "MULT" || s == "DIV");
}
//it needs to be expr -> expr + term or term
//				expr -> term * factor or factor
//				factor -> (expr) or number
//				number -> number digit or digit
//				digit -> 0123456789

/* check the last element's type and if it is not a number
the expression is not correct so return false, and probably I will have to add a message (?)
Here I assumed that the types are already made in the Token class:
NUM :		a number
ASSIGN :	 is the same as "="
NAME :		it will be the expression name such as name
ADD, SUB, MULT, DIV : are "+", "-", "*", and "/"
*/
bool SemanticAnalysis(std::vector<Token> tokens){
	bool output = true;
	// we will check the sequence and they need to be according to the rules.
	// types NAME, NUM, ADD or SUB or MULT or DIV
	if (tokens.size() >= 2){ // must be more or equal to 3 otherwise return false
		Token current_token;
		std::string current_type,previous_type = "";
		for(unsigned int i=0;i<tokens.size();i++){
			current_token = tokens[i];
			current_type = current_token.type;
			// if this is the first token or the previous token was an operator, the next token must be a number
			if (previous_type == "" || is_operator(previous_type)){
				if (is_operator(current_type)){
					std::cout<<"operator must be preceded by number"<< std::endl;
					output = false;
					break;
				}
			}else	if (previous_type == "NUM"){
				if(!is_operator(current_type)){
					std::cout<<"multiple consecutive numbers. what do you expect us to do with that?"<< std::endl;
					output = false;
					break;
				}
			}
			previous_type = current_type;
		}
	}else{
		std::cout<<"insufficient tokens"<< std::endl;
		output = false;
	}
	return output;
};
