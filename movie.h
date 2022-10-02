#include "product.h"
using namespace std;

class Movie: public Product{

  public:
  Movie(const std::string category, const std::string name, double price, int qty, const std::string genre, const std::string rating);
  virtual ~Movie();

	/**
  * Returns the appropriate keywords that this product should be associated with
  */
  std::set<std::string> keywords() const;

	/**
  * Returns a string to display the product info for hits of the search
  */
  std::string displayString() const;

  /**
  * Outputs the product info in the database format
  */
  void dump(std::ostream& os) const;

  private:
  std::string genre_;
  std::string rating_;

};