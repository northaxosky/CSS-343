// Kuzey Gok
// CSS 343
// Shop Class Header
// The shop class is a general implementation of the business. The shop
// has an object Inventory that serves as its stock, along with a hash
// table of customers to the business.
#ifndef SHOP_ASS_4
#define SHOP_ASS_4
#include <iostream>
#include <fstream>
#include "movie.h"
#include "customer.h"
#include "inventory.h"
#include "hashtable.h"
using namespace std;

class Shop  {
    // Constructor & Destructor
    Shop();
    ~Shop();
    
    // add and find customers
    void addCustomer(Customer* customer);
    Customer* findCustomer(int id);

    // display information about the shop
    void display();

private:
    // Inventoy of the shop, Hash table of customers
    Inventory main;
    HashTable<int, Customer*> customers;
};

#endif