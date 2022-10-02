#ifndef MYDATASTORE_H
#define MYDATASTORE_H

#include "datastore.h"
#include "product.h"
#include "user.h"
#include <map>
#include <deque>
#include <vector>

using namespace std;

class MyDataStore: public DataStore {
public:

		MyDataStore();
		virtual ~MyDataStore();

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

		void addToCart(std::string username, Product* p);
		void viewCart(std::string username);
		void buyCart(std::string username);

		private:
		std::vector<Product*> products;
		std::map<std::string, User*> users;
		std::map<std::string, deque<Product*>> users_cart;
		std::map<std::string, std::vector<Product*>> keyword_products;

};

#endif
