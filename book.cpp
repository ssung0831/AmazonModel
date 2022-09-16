#include "book.h"
#include "util.cpp"

using namespace std;


	Book::Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author):
		Product(category, name, price, qty)
	{
		isbn_ = isbn;
		author_ = author;

	}

	Book::~Book()
	{

	}

	/**
  * Returns the appropriate keywords that this product should be associated with
  */
  std::set<std::string> Book::keywords() const{
		std::set<std::string> keywords;
		std::set<std::string> parsed_author = parseStringToWords(author_);
		for(std::set<std::string>::iterator i = parsed_author.begin(); i != parsed_author.end(); ++i){
			keywords.insert(*i);
		}

		keywords.insert(isbn_);
		
		return keywords;
	}

	/**
  Returns a string to display the product info for hits of the search
	<name>
	Author: <author> ISBN: <isbn>
	<price> <quantity> left.
  */
  std::string Book::displayString() const{
		std::string info = name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left";
		return info;
	}

  /**
  * Outputs the product info in the database format
  */
  void Book::dump(std::ostream& os) const{
		cout << name_ << '\n' << "Author: " << author_ << " ISBN: " << isbn_ << '\n' << price_ << " " << qty_ << " left";
	}
