// Kuzey Gok
// CSS 343
// Parser Class Header
// The parser class is used to parse the input files given
// and act accordingly for the business.
#ifndef PARSER_ASS_4
#define PARSER_ASS_4
#include <iostream>
#include <fstream>
#include "movie.h"
#include "customer.h"
#include "inventory.h"
using namespace std;

class Parser    {
public:
    // Constructor and Destructor
    Parser();
    ~Parser();

    // Parse inventory, customer, and transaction files
    void parseInventory();
    void parseCustomers();
    void parseTransactions();
};

#endif