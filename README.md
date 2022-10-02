Modified Amazon

This code is a model of Amazon, the online retail system. 
It stores a database of products from Books, Clothing, and Movies.
Different users are able to add the products to their carts and purchase them.

Part 1:
To compile parseStringToWords() tester:
g++ -g -Wall util_test.cpp util.cpp -o util_test

To run tester code:
./util_test

To compile Child classes of Product:
g++ -g -Wall -std=c++11 -c [product].cpp

Part 2:
To compile Amazon:
make clean, 
make

To run:
./amazon database.txt

