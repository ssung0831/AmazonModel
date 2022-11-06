#include "book.h"
#include "util.h"

using namespace std;


	Book::Book(const std::string category, const std::string name, double price, int qty, std::string isbn, std::string author):
		Product::Product(category, name, price, qty), isbn_(isbn), author_(author)
	{

	}

	Book::~Book()
	{

	}

	/**
  * Returns the appropriate keywords that this product should be associated with
  */
  std::set<std::string> Book::keywords() const{
		std::set<std::string> keywords = parseStringToWords(convToLower(name_));
		std::set<std::string> authorParsed = parseStringToWords(convToLower(author_));
		for(std::set<std::string>::iterator i = authorParsed.begin(); i != authorParsed.end(); ++i){
			keywords.insert(*i);
		}
		keywords.insert(convToLower(isbn_));
		
		return keywords;
	}

	/**
  Returns a string to display the product info for hits of the search
	<name>
	Author: <author> ISBN: <isbn>
	<price> <quantity> left.
  */
  std::string Book::displayString() const{
				string ps = to_string(price_).substr(0, to_string(price_).find(".") +3);
		std::string info = name_ + "\n" + "Author: " + author_ + " ISBN: " + isbn_ + "\n" + ps + " " + to_string(qty_) + " left";
		return info;
	}

  /**
  * Outputs the product info in the database format
  */
  void Book::dump(std::ostream& os) const{
		string ps = to_string(price_).substr(0, to_string(price_).find(".") +3);
		os << category_ << endl << name_ << endl << ps << endl << to_string(qty_) << endl << isbn_ << endl << author_ << endl;
	}
