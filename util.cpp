#include <iostream>
#include <sstream>
#include <algorithm>
#include "util.h"

using namespace std;
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(std::string rawWords)
{
    std::set<std::string> parsed_words;
    
		// unsigned int index = 0;
    // int length= 0;
		// int prev = 0;

    // while(index < rawWords.length()){
    //     if(!isalpha(rawWords[index])){
    //       if(length >= 2){
    //         parsed_words.insert(convToLower(rawWords.substr(prev, length)));
		// 			}
		// 			prev = index + 1;
		// 			length = 0;
    //     }
		// 		else{
		// 			length++;
		// 		}
    //     index++;
    // }

		// if(length >= 2){
		// 	parsed_words.insert(convToLower(rawWords.substr(prev, rawWords.length() - 1)));
		// }

		//this is to ignore any punctuations that are in the string
		for(unsigned int i = 0; i < rawWords.length(); i++){
			if(ispunct(rawWords[i])){
				rawWords[i] = ' ';
			}
		}

		stringstream ss(rawWords);
		string word;
		//iterate through each word and only add words that are >= 2
		while(ss >> word){
			if(word.length() >= 2){
				parsed_words.insert(word);
			}
		}

    return parsed_words;
}

/**************************************************
 * COMPLETED - You may use the following functions
 **************************************************/

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// trim from start
std::string &ltrim(std::string &s) {
    s.erase(s.begin(), 
	    std::find_if(s.begin(), 
			 s.end(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))));
    return s;
}

// trim from end
std::string &rtrim(std::string &s) {
    s.erase(
	    std::find_if(s.rbegin(), 
			 s.rend(), 
			 std::not1(std::ptr_fun<int, int>(std::isspace))).base(), 
	    s.end());
    return s;
}

// trim from both ends
std::string &trim(std::string &s) {
    return ltrim(rtrim(s));
}

// int main(){
// 	set<string> t = parseStringToWords("Hidden Figures");
// 	for(set<string>::iterator it = t.begin(); it != t.end(); ++it){
// 		cout << *it << endl;
// 	}
// 	cout << endl;
// }