#include <iostream>
#include <sstream>
#include <cctype>
#include <algorithm>
#include "util.h"

using namespace std;
int main () {
    // main method
    string allMyWords = "item! c!iip hello what's Men's I'll mov,e";
    set<string> allWords = parseStringToWords(allMyWords);
    // cout all the words in the set 
    for (set<string>::iterator it = allWords.begin();
    it != allWords.end(); ++it) {
        cout << *it << endl;
    }
}
std::string convToLower(std::string src)
{
    std::transform(src.begin(), src.end(), src.begin(), ::tolower);
    return src;
}

/** Complete the code to convert a string containing a rawWord
    to a set of words based on the criteria given in the assignment **/
std::set<std::string> parseStringToWords(string rawWords) {
    // assuming that the words are split with spaces 
    // we can eliminate the spaces and add the single word into the set 
    // of words that we create and then return the set

    // we must account for the punctuations and the words must be
    // at least two characters or more...
    std::set<std::string> words;
    std::string word = "";
    for (unsigned int i = 0; i < rawWords.length(); ++i) {
        // this means we are at the end of a whole word
        if (isspace(rawWords[i]) || !isalnum(rawWords[i])) {
            // check the length of the word
            if (word.length() >= 2) {
                // insert into the set as a lowercase word
                words.insert(convToLower(word));
                // clean slate 
                word = "";
            }
            else {
                // discard the word if it is less than 
                // 2 characters
                word = "";
            }
        }
        else {
            // word is an alphanumerical character so we 
            // can continue concatenating into the word
            word += rawWords[i];
        }
    }
    return words;
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
