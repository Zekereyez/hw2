#ifndef UTIL_H
#define UTIL_H

#include <string>
#include <iostream>
#include <set>


/** Complete the setIntersection and setUnion functions below
 *  in this header file (since they are templates).
 *  Both functions should run in time O(n*log(n)) and not O(n^2)
 */
template <typename T>
std::set<T> setIntersection(std::set<T>& s1, std::set<T>& s2) {
	// so the main idea will be to create a set and then insert
	// into that set the items which have only matching elements in 
	// both sets and then return that set 

	// traverse through one set and use the find function to 
	// see if that element exists in the other set and if not 
	// we do not add only if both the items exist in each set
	// so if we run out of iterations in one set ie one set is larger
	// than the other then we can discard the elements and not insert
	// into the intersected set since cant match sgsgsgsg
	typename std::set<T> intersectedSet;
	for (typename std::set<T>::iterator it = s1.begin(); it != s1.end(); ++it) {
		// if the item in s1 is found in s2 we can then insert it 
		if (s2.find(*it)) {
			intersectedSet.insert(*it);
		}
	}
	// to create an iterator for the set because it is templated 
	// we would have to precede it with typename set<T>::iterator it
	// easy shit
	return intersectedSet;
}
template <typename T>
std::set<T> setUnion(std::set<T>& s1, std::set<T>& s2) {
	// for this function need to create a set that will hold the 
	// the items of distinct set elements from both sets
	// into the made set and then return said set 
	typename std::set<T> unionedSet = s2;
	
	// is this allowed??
	// unionedSet.insert(s2.begin(), s2.end());
	// unionedSet.insert(s1.begin(), s1.end());

	// or 
	
	for (typename std::set<T>::iterator it = s1.begin(); it != s1.end(); ++it) {
		if (!unionedSet.find(*it)) {
			unionedSet.insert(*it);
		}
	}
	return unionedSet;
	// okay lgtm can test it later on
}

/***********************************************/
/* Prototypes of functions defined in util.cpp */
/***********************************************/

std::string convToLower(std::string src);

std::set<std::string> parseStringToWords(std::string line);

// Used from http://stackoverflow.com/questions/216823/whats-the-best-way-to-trim-stdstring
// Removes any leading whitespace
std::string &ltrim(std::string &s) ;

// Removes any trailing whitespace
std::string &rtrim(std::string &s) ;

// Removes leading and trailing whitespace
std::string &trim(std::string &s) ;
#endif
