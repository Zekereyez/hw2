#include "clothing.h"

Clothing::Clothing (const std::string category, const std::string name, double price, 
	int qty, std::string size, std::string brand) : Product (category, name, price, qty)
 {
	 // should use an initialization list here for the items... 
 }
std::set<std::string> Clothing::keywords(){
	// ditto
}

std::string Clothing::displayString(){
	// ditto
}

void Clothing::dump(std::ostream& os) const {
	// fill in 
}