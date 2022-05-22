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
    Parser();
    ~Parser();
    void parseInventory();
    void parseCustomers();
    void parseTransactions();
};

#endif