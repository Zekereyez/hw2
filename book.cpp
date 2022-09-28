#include "book.h"

Book::Book (const std::string category, const std::string name, double price, 
	int qty, std::string isbn, std::string author) : Product (category, name, price, qty)
 {
	 // should use an initialization list here for the items... 
 }

std::set<std::string> Book::keywords(){
	// fill in 
}

std::string Book::displayString() {
	// fill in 
}

void Book::dump(std::ostream& os) const {
	// fill in 
}
