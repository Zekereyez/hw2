#ifndef BOOK_H
#define BOOK_H
#include <string>
#include "product.h"

class Book : public Product {
	public:
		// Book(); this might not be needed
		// each derived product class needs to Implement
		// functions like keywords() displayString() 
		// and dump() so we need these
		Book(const std::string category const std::string name, double price,
			int qty, std::string isbn, std::string author);
		std::set<std::string> keywords();
		std::string displayString();
		void dump(std::ostream& os) const;

	private:
		// create private shit here
		std::string author;
		std::string isbn;
}

class Course { 
	public:
		Course();
		std::string getCourseName();
		void setCourseName(std::string courseName);
		std::set<Assignment*> getAssignmentSet();
		void addAssignment(Assignment* a);

	private: 
		std::set<Assignment*> mAssignmentSet;
		std::string mCourseName;
};