#include "mydatastore.h"
#include "product.h"
#include "user.h"
#include "util.h"
using namespace std;

		MyDataStore::MyDataStore(){
		}
    
		MyDataStore::~MyDataStore() { 
			for(vector<Product*>::iterator i = products.begin(); i != products.end(); ++i){
				delete *i;
			}

			for(map<string, User*>::iterator j = users.begin(); j != users.end(); ++j){
				delete j -> second;
			}
		}

    /**
     * Adds a product to the data store
     */
		void MyDataStore::addProduct(Product* p){
			products.push_back(p);

			//for each of the product's keywords, add this product to its map
			set<string> keyWords = p -> keywords();
			for(set<string>::iterator i = keyWords.begin(); i != keyWords.end(); ++i){
			
				//keyword doesn't exist yet
				map<string, vector<Product*>>::iterator j = keyword_products.find(*i);
				if(j == keyword_products.end()){
					vector<Product*> prod;
					prod.push_back(p);
					keyword_products.insert(std::make_pair(convToLower(*i), prod));
				}
				else{
					(j -> second).push_back(p);
				}
			}
		}

    /**
     * Adds a user to the data store
     */
    void MyDataStore::addUser(User* u){
			users.insert(make_pair(convToLower(u-> getName()), u));
			deque<Product*> c;
			users_cart.insert(make_pair(convToLower(u-> getName()), c));
		}

    /**
     * Performs a search of products whose keywords match the given "terms"
     *  type 0 = AND search (intersection of results for each term) while
     *  type 1 = OR search (union of results for each term)
     */
    std::vector<Product*> MyDataStore::search(std::vector<std::string>& terms, int type){
		
			bool firstTime = true;
			std::set<Product*> results;

			//iterate through each term
			for(vector<string>::iterator i = terms.begin(); i != terms.end(); ++i){
				std::set<Product*> temp;
				map<string, vector<Product*>>::iterator j = keyword_products.find(*i);
				//each term has a list of products that match, we are going to put them together through intersections/unions
				if(j != keyword_products.end()){
					//put all the products in our sets
					vector<Product*> p = j -> second;
					for(vector<Product*>::iterator k = p.begin(); k != p.end(); ++k){
						if(firstTime){
							results.insert(*k);
						}
						temp.insert(*k);
					}

					firstTime = false;

					if(type == 0) //and- intersection
					{
						results = setIntersection(results, temp);
					}
					else if(type == 1) //or- union
					{
						results = setUnion(results, temp);
					}
			 	}
			}

			vector<Product*> prodResults;
			for(set<Product*>::iterator it = results.begin(); it != results.end(); ++it){
				prodResults.push_back(*it);
			}
			return prodResults;

		}

    /**
     * Reproduce the database file from the current Products and User values
     */
    void MyDataStore::dump(std::ostream& ofile){
			ofile << "<products>" << endl;

			for(vector<Product*>::iterator i = products.begin(); i!= products.end(); ++i){
				(*i) -> dump(ofile);
			}
			ofile << "</products>" << endl;

			ofile << "<users>" << endl;
			for(std::map<string, User*>::iterator j = users.begin(); j!= users.end(); ++j){
				j -> second -> dump(ofile);
			}
			ofile << "</users>" << endl;
		}

		void MyDataStore::addToCart(string username, Product* p){
			bool userExists = false;
			map<string, deque<Product*>>::iterator i = users_cart.find(username);
				//check if this is the user
				if(i != users_cart.end()){
					userExists = true;
					(i -> second).push_back(p);
				}

			if(!userExists){
				cout << "Invalid" << endl;
			}
		}

		void MyDataStore::viewCart(string username){
			map<string, deque<Product*>>::iterator i = users_cart.find(username);
				//check if this is the user
				if(i != users_cart.end()){
					//iterate through cart and display
					int index = 1;
					for(deque<Product*>::iterator j = (i -> second).begin(); j != (i -> second).end(); ++j){
						cout << index << ". " << (*j) -> displayString() << endl;
						index++;
						cout << '\n';
		  		}
				}
			else{
				cout <<"Invalid Username" << endl;
			}
		}

		void MyDataStore::buyCart(string username){
			bool userExists = false;
			map<string, deque<Product*>>::iterator i = users_cart.find(username);
				//check if this is the user
				if(i != users_cart.end()){
					userExists = true;
					deque<Product*> myCart = i -> second;
					map<string, User*>::iterator thisUser = users.find(username);

					for(deque<Product*>::iterator j = myCart.begin(); j != myCart.end(); ++j){
						//if product is in stock and user has enough money
						if(((*j)->getQty() > 0) && ((thisUser) -> second -> getBalance() >= (*j)->getPrice())){
							(*j)->subtractQty(1);
							double amount = (*j) ->getPrice();
							thisUser->second->deductAmount(amount);
							(i -> second).pop_front();
						}
						else{
							(i -> second).push_back(*j);
							(i -> second).pop_front();
						}
					}
				}

				if(!userExists){
					cout << "Invalid Username" << endl;
				}
			}
		
		