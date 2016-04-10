#include "scanner.h"
#include "TokenCreator2.h"
#include "SemanticAnalysis.h"
#include "expressionParser.h"

void dumpToken (std::vector<Token> &lv, std::string &s);
bool is_operator(std::string s);
std::vector<Token> tokenCreator(std::vector<char> Input);
bool SemanticAnalysis(std::vector<Token> tokens);
double parseExpression(std::vector<Token> tokens);

