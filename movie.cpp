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
		std::set<std::string> keywords = parseStringToWords(name_);
		std::set<std::string> genreParsed = parseStringToWords(genre_);
		for(std::set<std::string>::iterator i = genreParsed.begin(); i != genreParsed.end(); ++i){
			keywords.insert(*i);
		}
		return keywords;
	}

	/**
  Returns a string to display the product info for hits of the search
	<name>
	Genre: <genre> Rating: <rating>
	<price> <quantity> left.
  */
  std::string Movie::displayString() const{
		std::string info = name_ + "\n" + "Genre: " + genre_ + " Rating: " + rating_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left";
		return info;
	}

  /**
  * Outputs the product info in the database format
  */
  void Movie::dump(std::ostream& os) const{
		os << name_ << '\n' << "Genre: " << genre_ << " Rating: " << rating_ << '\n' << price_ << " " << qty_ << " left";
	}