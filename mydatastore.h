#ifndef MYDATASTORE_H
#define MYDATASTORE_H
#include <string>
#include <set>
#include <vector>
#include <map>
#include <queue>
#include "product.h"
#include "user.h"
#include "util.h"

using namespace std;

/**
 * DataStore Interface needed for parsing and instantiating products and users
 *
 * A derived version of the DataStore can provide other services as well but
 * must support those below
 *
 * DO NOT EDIT
 */


class MyDataStore : public DataStore {
public:
		// constructor
  	MyDataStore() { }

		// destructor
		~MyDataStore();

    /**
     * Adds a product to the data store
     */
    void addProduct(Product* p);

    /**
     * Adds a user to the data store
     */
    void addUser(User* u);

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> search(std::vector<std::string>& terms, int type);

    /**
     * Reproduce the database file from the current Products and User values
     */
    void dump(std::ostream& ofile);

		// TODO: MAKE FUNCTION FOR MENU COMMANDS
		// FOR EACH COMMAND THERE IS 
		void addProductToUsersCart(string username, Product *product);
		void buyUsersCart(string username);
		void viewUsersCart(string username);

	// private data members and structures
	private:
		// for cart, product, and users use maps 
		// want to associate username to user
		// keywords to products

		// keep map in data store as a member data structure
		// product name to product object
		map <string, Product *> products;
		// username to user object
		map <string, Users *> users;
		// product keyword to set of products with keyword 
		map <string, set <Product *> > keywordToProducts;
		// for the cart we want to associate the username of the 
		// user to the products they want to buy so something 
		// along the lines of a vector or see how the cart should 
		// operate for fifo or if its filo 
		map <string, queue <Product *> > allUsersCart;

		// TODO: Fix the display string so that the format of it 
		// meets the requirements of what's on the right side 
		// easy enough to do really for books, movies, clothing


		// do the same for user and etc 
		



};

#endif
