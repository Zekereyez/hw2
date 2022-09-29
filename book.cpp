#include "book.h"
#include "util.h"
#include <iostream>
#include <sstream>

using namespace std;

Book::Book (const std::string category, const std::string name, double price, 
	int qty, std::string isbn, std::string author) : Product (category, name, price, qty),
	isbn(isbn), author(author)
 {
	 // should use an initialization list here for the items... 
 }

std::set<std::string> Book::keywords(){
	// fill in 
	std::set<std::string> newSet;
	// need to insert the product key words used in util
	// then need to manually insert the items that 
	// are item specific to the product such as size and brand
	newSet.insert(isbn);
	newSet.insert(convToLower(author));
	newSet.insert(convToLower(category));
	// parseStringToWords returns a set so we can use that with the set union
	return setUnion(parseStringToWords(getName()), newSet);

}

std::string Book::displayString() {
	// creates a string that contains the product info
	/*<products>
	product_category
	name
	price
	quantity
	category-specific-info
	product_category
	name
	price
	quantity
	category-specific-info
	...
	</products> */
	ostringstream oss;
	oss << category_ << endl;
	oss << getName() << endl;
	oss << getPrice() << endl;
	oss << getQty() << endl;
	oss << isbn << endl;
	oss << author << endl;
	// returns a string object with a copy of the current contents of the stream
	return oss.str();
}

void Book::dump(std::ostream& os) const {
	// outputs the database format of the product info
	// just call displayString and output that 
	cout << displayString();
}
