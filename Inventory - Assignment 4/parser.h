// Kuzey Gok
// CSS 343
// Parser Class Header
// The parser class is used to parse the input files given
// and act accordingly for the business.
#pragma once
#ifndef PARSER_ASS_4
#define PARSER_ASS_4
#include <iostream>
#include <string>
#include <sstream>
#include <fstream>
#include <algorithm>
#include "movie.h"
#include "customer.h"
#include "shop.h"
#include "comedy.h"
#include "drama.h"
#include "classic.h"
using namespace std;

class Parser    {
public:
    Parser() {}
    ~Parser() {}
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