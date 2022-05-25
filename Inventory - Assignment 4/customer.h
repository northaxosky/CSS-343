#ifndef CUSTOMER_ASS_4
#define CUSTOMER_ASS_4
#include "hashtable.h"
#include <string>
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
    vector<string> history;
    HashTable<string, int> collection;

    int id;
    string name;
};

#endif