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
public:
    // Constructor & Destructor
    Shop();
    ~Shop() = default;
    
    // add and find customers and movies
    void addCustomer(Customer* customer);
    Customer* findCustomer(int id);
    void addMovie(Movie* movie);
    Movie* findMovie(string name);

    // Process Transactions
    void processInventory();
    void processHistory(int id);
    void processBorrow(int id, char type, string details, string command);
    void processReturn(int id, char type, string details, string command);
    

    // display information about the shop
    void display();

private:
    struct CustomerHash
    {
        unsigned long operator()(const int& key) const  {
            return key % SIZE;
        }
    };
    
    // Inventoy of the shop, Hash table of customers
    Inventory inventory;
    HashTable<int, Customer*, CustomerHash> customers;
};

#endif