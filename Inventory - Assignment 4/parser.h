// Kuzey Gok
// CSS 343
// Parser Class Header
// The parser class is used to parse the input files given
// and act accordingly for the business.
#ifndef PARSER_ASS_4
#define PARSER_ASS_4
#include <iostream>
#include <fstream>
#include <string>
#include <sstream>
#include <istream>
#include <algorithm>
#include "movie.h"
#include "customer.h"
#include "inventory.h"
#include "shop.h"
#include "comedy.h"
#include "classic.h"
#include "drama.h"
using namespace std;

class Parser    {
public:
    Parser();
    ~Parser() = default;

    // Parse inventory, customer, and transaction files
    void parseInventory(string name);
    void parseCustomers(string name);
    void parseTransactions(string name);

    Movie* createMovie(string line);
    Customer* createCustomer(string line);
    void processTransaction(string line);
    void parseString(string& str, const string& chars);
private:
    Shop shop;
};

#endif