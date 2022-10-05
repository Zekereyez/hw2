#include "mydatastore.h"


using namespace std;

MyDataStore:MyDataStore () {}

MyDataStore:~MyDataStore () {}

/**
* Adds a product to the data store
*/
void MyDataStore::addProduct(Product* p) {
	// add the product
	// extract the name from object
	string productName = convToLower( p->getName() );
	products.insert(make_pair(productName, p));

	// for each product we need to get the keywords that 
	// match it and then iterate through the set of keywords and
	// insert each keyword into the set of product that matches or has
	// said keyword in it -- ie this will be a lot of iteration, conditional 
	// checking and insertion
	set <string> productKeyWords = parseStringToWords(productName);
	// with this set of keywords I need to iterate through it and 
	// check if each keyword has a key in the map of keywords 
	// if not create a new map key and insert a set with the product 
	// inside of the set. 
	set <string>::iterator it = productKeyWords.begin();
	// map <string, set <Product *> > keywordToProducts;
	map <string, set <Product *> >::iterator jt;
	for (; it != productKeyWords.end(); ++it) {
		jt = keywordToProducts.find(*it);
		if (jt == keywordToProducts.end()) {
			// this means the keyword does not exist and we need to insert 
			// the set and keyword 
			set <Product *> newProductSet;
			newProductSet.insert(p);
			keywordToProducts.insert(make_pair(*it, newProductSet));
		}
		else {
			// the keyword key is found then we need to insert into the 
			// set of that key and jt is now a valid iterator to use hehehe
			jt->second.insert(p);
		}
	} 
}

/**
* Adds a user to the data store
*/
void MyDataStore::addUser(User* u) {
	// add the user here 
	string username = convToLower( u->getName() );
	users.insert(make_pair(username, u));
	// each added user should get a new clean slate cart
	queue <Product *> userCart;
	allUsersCarts.insert(make_pair(username, userCart));
}

/**
* Performs a search of products whose keywords match the given "terms"
*  type 0 = AND search (intersection of results for each term) while
*  type 1 = OR search (union of results for each term)
*/
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
	// perform the search of products here 
	// Search: use the set intersection and setunion functions
	// inside of util.h 
	vector <Product *> searchResultOfProducts;
	// so we have a vector with the terms we need to check through the 
	// the keywordToProducts map and snag the resulting sets and then
	// from there we are able to do the set intersection or even set 
	// union of the terms and then return the set inserted into the 
	// vector of product objects 
	set <Product *> setOfProducts;
	vector<string>::iterator it = terms.begin();
	for (; it != terms.end(); ++it) {
		// we want to iterate and check if map has the 
		// terms in it and then set those terms to the 
		// setOfProducts and from there either do type 1 or 0
		// search set calls until we finish and have a resulting
		// set with the correct products in it
	}
	// at the end of the loop we assume that the set is filled with
	// the correct products in it and we can then fill the 
	// vector with the products from the set - easy way to do this?
	// ans: use the assign or can even use the constructor to do this
	searchResultOfProducts.assign(setOfProducts.begin(), setOfProducts.end());
	return searchResultOfProducts;

}

/**
* Reproduce the database file from the current Products and User values
*/
void MyDataStore::dump(std::ostream& ofile) {
	// look at the dump examples for formatting on the dump
}

// TODO: MAKE FUNCTION FOR MENU COMMANDS
// FOR EACH COMMAND THERE IS 
void MyDataStore::addProductToUsersCart(string username, Product *product) {
	// add product to the cart
}

void MyDataStore::buyUsersCart(string username) {
	// buy the cart, check balance?
}
void MyDataStore::viewUsersCart(string username) {
	// view the users cart here do we dump it??
}