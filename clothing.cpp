#include "clothing.h"
#include "util.h"
#include <ostream>
#include <sstream>

using namespace std; 

Clothing::Clothing (const std::string category, const std::string name, double price, 
	int qty, std::string size, std::string brand) : Product (category, name, price, qty),
	size(size), brand(brand)
 {
	 // should use an initialization list here for the items... 
 }
std::set<std::string> Clothing::keywords() const {
	// ditto
	std::set<std::string> newSet;
	// need to insert the product key words used in util
	// then need to manually insert the items that 
	// are item specific to the product such as size and brand
	newSet.insert(convToLower(category_));
	newSet.insert(convToLower(size));
	newSet.insert(convToLower(brand));
	// parseStringToWords returns a set so we can use that with the set union
	set<string> stringToWord = parseStringToWords(getName());
	return setUnion(stringToWord, newSet);
}

std::string Clothing::displayString() const {
	// ditto
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
	oss << size << endl;
	oss << brand << endl;
	// returns a string object with a copy of the current contents of the stream
	return oss.str();
}

void Clothing::dump(std::ostream& os) const {
	// fill in 
  Product::dump(os);
  os << size << "\n" << brand << "\n";
	// std::cout << displayString();
}