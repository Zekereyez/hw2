#include "movie.h"

Movie::Movie (const std::string category, const std::string name, double price, 
	int qty, std::string genre, std::string rating) : Product (category, name, price, qty), 
	genre(genre), rating(rating)
 {
	 // should use an initialization list here for the items... 
 }


std::set<std::string> Movie::keywords() {
	// fill in 
	std::set<std::string> newSet;
	// need to insert the product key words used in util
	// then need to manually insert the items that 
	// are item specific to the product such as size and brand
	newSet.insert(convToLower(genre));
	newSet.insert(convToLower(rating));
	newSet.insert(convToLower(category));
	// parseStringToWords returns a set so we can use that with the set union
	return setUnion(parseStringToWords(getName()), newSet);
}

std::string Movie::displayString() {
	// fill in 
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
	oss << genre << endl;
	oss << rating << endl;
	// returns a string object with a copy of the current contents of the stream
	return oss.str();
}

void Movie::dump(std::ostream& os) const {
	// fill in 
	cout << displayString();
}

