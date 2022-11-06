#include "movie.h"
#include "util.h"

using namespace std;

Movie::Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating):
	Product::Product(category, name, price, qty), genre_(genre), rating_(rating)
{

}

Movie::~Movie()
{

}

	/**
  * Returns the appropriate keywords that this product should be associated with
  */
  std::set<std::string> Movie::keywords() const{
		std::set<std::string> keywords = parseStringToWords(convToLower(name_));
		keywords.insert(convToLower(genre_));

		return keywords;
	}

	/**
  Returns a string to display the product info for hits of the search
	<name>
	Genre: <genre> Rating: <rating>
	<price> <quantity> left.
  */
  std::string Movie::displayString() const{
				string ps = to_string(price_);
				ps = ps.substr(0, to_string(price_).find(".") +3);
		std::string info = name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + ps + " " + to_string(qty_) + " left";
		return info;
	}

  /**
  * Outputs the product info in the database format
  */
  void Movie::dump(std::ostream& os) const{
		string ps = to_string(price_);
		ps = ps.substr(0, to_string(price_).find(".") +3);
		os << category_ << endl << name_ << endl << ps << endl << to_string(qty_) << endl << genre_ << endl << rating_ << endl;
	}