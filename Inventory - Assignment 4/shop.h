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
    Shop();
    ~Shop();
    
    void addCustomer(Customer* customer);
    Customer* findCustomer(int id);
    void display();

private:
    Inventory main;
    HashTable<int, Customer*> customers;
};

#endif