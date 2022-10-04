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
	string productName = p->getName();
	products.insert(make_pair(convToLower(productName), p));

	// for each product we need to get the keywords that 
	// match it and then iterate through the set of keywords and
	// insert each keyword into the set of product that matches or has
	// said keyword in it -- ie this will be a lot of iteration, conditional 
	// checking and insertion


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
}

/**
* Reproduce the database file from the current Products and User values
*/
void MyDataStore::dump(std::ostream& ofile) {
	// look ath the dump examples for formatting on the dump
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