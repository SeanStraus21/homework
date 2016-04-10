/**
* LAST MODIFIED DATE:03/04/2016
* CLASSES: Scanner
*/
#include <string>
#include <vector>
#include <iostream>

class Scanner{
 private:
 std::string source;

 /**
 Scanner Class
 Scans Input
 */
 public:
  Scanner(){
  }
  /**
  scan()
  takes lines from input and converts to a vector of chars
  */
  std::vector<char> scan(){
		std::string token;
		source = "";
		getline(std::cin,source);
		//while (getline(std::cin,token)){
		//	source = source + token;
		//}
		std::string current_token;
		std::vector<char> output = std::vector<char>();
		char current_char;
		for(unsigned int i=0;i<source.length();i++){
			current_char = source[i];
			output.push_back(current_char);
		}
		return output;
  }
};
