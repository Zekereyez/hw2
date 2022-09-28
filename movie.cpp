#include "movie.h"

Movie::Movie (const std::string category, const std::string name, double price, 
	int qty, std::string genre, std::string rating) : Product (category, name, price, qty)
 {
	 // should use an initialization list here for the items... 
 }


std::set<std::string> Movie::keywords() {
	// fill in 
}

std::string Movie::displayString() {
	// fill in 
}

void Movie::dump(std::ostream& os) const {
	// fill in 
}

