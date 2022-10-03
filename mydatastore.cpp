#include "mydatastore.h"
#include "util.h"

using namespace std;

MyDataStore:MyDataStore () {}

MyDataStore:~MyDataStore () {}

/**
* Adds a product to the data store
*/
void MyDataStore::addProduct(Product* p) {
	// add the product
}

/**
* Adds a user to the data store
*/
void MyDataStore::addUser(User* u) {
	// add the user here 
}

/**
* Performs a search of products whose keywords match the given "terms"
*  type 0 = AND search (intersection of results for each term) while
*  type 1 = OR search (union of results for each term)
*/
std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type) {
	// perform the search of products here 
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