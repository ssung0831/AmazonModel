#include <sstream>
#include <iomanip>
#include "product.h"

using namespace std;

Product::Product(const std::string category, const std::string name, double price, int qty) :
    name_(name),
    price_(price),
    qty_(qty),
    category_(category)
{

}

Product::~Product()
{

}


double Product::getPrice() const
{
    return price_;
}

std::string Product::getName() const
{
    return name_;
}

void Product::subtractQty(int num)
{
    qty_ -= num;
}

int Product::getQty() const
{
    return qty_;
}

/**
 * default implementation...can be overriden in a future
 * assignment
 */
bool Product::isMatch(std::vector<std::string>& searchTerms) const
{
    return false;
}

void Product::dump(std::ostream& os) const
{
	string ps = to_string(price_);
		ps = ps.substr(0, to_string(price_).find(".") +3);
    os << category_ << "\n" << name_ << "\n" << ps << "\n" << to_string(qty_) << endl;
}



