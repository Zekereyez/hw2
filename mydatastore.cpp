#include "mydatastore.h"

using namespace std;

// MyDataStore::MyDataStore () {}

MyDataStore::~MyDataStore () {}

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
	vector <Product *> userCart;
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
	map <string, set <Product *> >:: iterator jt;
	for (; it != terms.end(); ++it) {
		// we want to iterate and check if map has the 
		// terms in it and then set those terms to the 
		// setOfProducts and from there either do type 1 or 0
		// search set calls until we finish and have a resulting
		// set with the correct products in it
		jt = keywordToProducts.find(*it);
		if (jt != keywordToProducts.end()) {
			// this means we have a valid set of products
			// we can't use set intersection on an empty set
			if (type == 0) {
				if (setOfProducts.size() == 0) {
					setOfProducts = jt->second;
				}
				else {
					// the size of the set isnt zero we can use intersection
					setOfProducts = setIntersection(setOfProducts, jt->second);
				}
			}
			else if (type == 1) {
				setOfProducts = setUnion(setOfProducts, jt->second);
			}
		}
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
void MyDataStore::addProductToUsersCart(string username, Product * product) {
	// add product to the cart
	// check if username is valid 
	map <string, vector <Product *> >::iterator it = allUsersCarts.find(username);
	if (it == allUsersCarts.end()) {
		cout << "invalid username" << endl;
		return;
	}
	else {
		// valid user in map
		// should use vector instead of queue??
		it->second.push_back(product);
	}
	
}

void MyDataStore::buyUsersCart(string username) {
	// buy the cart, check balance?
	// putting things you can't buy into a new vector
	// and then replacing the old vector with the vector of 
	// items that you could not buy -- 
	if (users.find(username) == users.end()) {
		cout << "invalid username";
		return;
	}
	else {
		// valid username 
		User * currentUser = users[username];
		// now get the cart of the user and buy shitttt
		vector <Product *> cartToBuy = allUsersCarts[username];
		vector <Product *> productsNotPurchased;
		for (unsigned int i = 0; i < cartToBuy.size(); ++i) {
			// use deductAmount and then need to deduct the qty of the 
			// item if able to buy if not able to buy insert into other
			// vector so we can put back into map - make sure to charge 
			double price = cartToBuy[i]->getPrice();
			int productQty = cartToBuy[i]->getQty();
			double userBalance = currentUser->getBalance();
			double remainingBalance = userBalance - price;
			if (productQty > 0 && (remainingBalance) > 0) {
				currentUser->deductAmount(price);
				cartToBuy[i]->subtractQty(1);
			}
			else if (productQty > 0 && (remainingBalance) < 0) {
				// this means that the item is in stock but we do not 
				// have the balance to buy the product so we need to 
				// add the product into the new vector 
				productsNotPurchased.push_back(cartToBuy[i]);
			}
		}
		// end of loop so now we can replace the users cart
		// will work as if cart is empty that means we cleared 
		// out the cart and have a new one 
		allUsersCarts[username] = productsNotPurchased;
	}
}
void MyDataStore::viewUsersCart(string username) {
	// view the users cart here do we dump it??
	// given a username we need to access the items of the 
	// cart 
	map <string, vector <Product *> >::iterator it = allUsersCarts.find(username);
	if (it == allUsersCarts.end()) {
		// user not found 
		cout << "invalid username";
		return;
	}
	else {
		// user is found so should have a cart
		// we have the iterator that points to the whole thing
		// we need to narrow it down to the vector of product 
		// and from there we can iterate through the vector and 
		// print it out 
		vector <Product *> userProductsInCart = it->second;
		// vector <Product *>::iterator jt = userProductsInCart.begin();
		for (unsigned int i = 0; i < userProductsInCart.size(); ++i) {
			cout << "Item " << i << ": " << endl;
			cout << userProductsInCart[i]->displayString() << endl;
		}
	}
}