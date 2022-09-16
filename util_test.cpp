#include "util.h"
#include <string>
#include <iostream>
#include <set>
#include <ctype.h>

using namespace std;

//Tester main function for parseStringToWords()
int main(){
    std::set<std::string> answer;
    std::string example = "Singin' in the Rain";
		answer = parseStringToWords(example);

	for(std::set<std::string>::iterator i = answer.begin(); i != answer.end(); ++i){
		std::cout << *i << '\n';
	}
}