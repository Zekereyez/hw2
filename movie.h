#ifndef MOVIE_H
#define MOVIE_H
#include "product.h"

class Movie : public Product {
	public:
		// Book(); this might not be needed
		// each derived product class needs to Implement
		// functions like keywords() displayString() 
		// and dump() so we need these
		Movie(const std::string category, const std::string name, double price, 
			int qty, std::string genre, std::string rating);
		std::set<std::string> keywords() const;
		std::string displayString() const;
		void dump(std::ostream& os) const;

	private:
		// create private shit here
		std::string genre;
		std::string rating;
};
#endif