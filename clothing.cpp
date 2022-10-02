#include "clothing.h"
#include "util.h"

using namespace std;


	Clothing::Clothing(const std::string category, const std::string name, double price, int qty, std::string size, std::string brand):
		Product::Product(category, name, price, qty),
		size_(size),
		brand_(brand)
	{

	}

	Clothing::~Clothing()
	{

	}

	/**
  * Returns the appropriate keywords that this product should be associated with
  */
  std::set<std::string> Clothing::keywords() const{
		std::set<std::string> keywords = parseStringToWords(name_);
		std::set<std::string> brandParsed = parseStringToWords(brand_);
		for(std::set<std::string>::iterator i = brandParsed.begin(); i != brandParsed.end(); ++i){
			keywords.insert(*i);
		}
		return keywords;
	}

	/**
	Returns a string to display the product info for hits of the search
	<name>
	Size: <size> Brand: <brand>
	<price> <quantity> left.
  */
  std::string Clothing::displayString() const{
		std::string info = name_ + "\n" + "Size: " + size_ + " Brand: " + brand_ + "\n" + to_string(price_) + " " + to_string(qty_) + " left";
		return info;
	}

  /**
  * Outputs the product info in the database format
  */
  void Clothing::dump(std::ostream& os) const{
		os << name_ << '\n' << "Size: " << size_ << " Brand: " << brand_ << '\n' << price_ << " " << qty_ << " left";
	}
