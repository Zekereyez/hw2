#ifndef CLOTHING_H
#define CLOTHING_H
#include "product.h"

class Clothing : public Product {
	public:
		// Book(); this might not be needed
		// each derived product class needs to Implement
		// functions like keywords() displayString() 
		// and dump() so we need these
		Clothing(const std::string category, const std::string name, double price, 
			int qty, std::string size, std::string brand);
		std::set<std::string> keywords() const;
		std::string displayString() const;
		void dump(std::ostream& os) const;

	private:
		// create private shit here
		std::string size;
		std::string brand;
};
#endif