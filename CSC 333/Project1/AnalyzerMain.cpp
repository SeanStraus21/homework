#include <string>
#include <iostream>
#include <stdlib.h>
#include <vector>
#include "frontend.h"

int main(int argc, char *argv[]){
	while(true){
		Scanner scanner = Scanner();
		std::vector<char> input = scanner.scan();
		if (input.size() == 0){break;}
		std::vector<Token> tokens = tokenCreator(input);
		if(SemanticAnalysis(tokens)){
			std::cout << parseExpression(tokens) << std::endl;
		}else{
			std::cout << "Invalid statement. Try doing better." << std::endl;
		}
	}
	return 0;
}
