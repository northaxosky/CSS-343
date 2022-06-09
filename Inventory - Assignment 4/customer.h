// Kuzey Gok
// CSS 343
// Customer Class Header
// The customer class is a class meant to store information on
// every unique customer of the business.
#ifndef CUSTOMER_ASS_4
#define CUSTOMER_ASS_4
#include "hashtable.h"
#include <string>
#include <vector>
using namespace std;

class Customer  {
public:
    // Constructor & Destructors
    Customer();
    Customer(int id, string name);
    ~Customer();

    // get and Set methods
    int getID() const;
    string getName() const;
    void getHistory() const;
    void addHistory(string hist);

    // borrow and return
    void borrow(Movie* movie);
    void release(Movie* movie);

private:
    // History and hashtable of borrowed movies
    vector<string> history;
    HashTable<string, int> collection;

    // Customer fields - ID & name
    int id;
    string name;
};

#endif