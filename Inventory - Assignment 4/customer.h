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
    friend ostream& operator<<(ostream& out, const Customer& cust);
public:
    // Constructor & Destructors
    Customer();
    Customer(string first, string last, int id);
    ~Customer();

    // get and Set methods
    int getID() const { return id; }
    string getName() const {return first + " " + last; };
    void getHistory() const;
    void addHistory(string hist);

    // borrow and return
    void borrow(Movie* movie);
    bool release(Movie* movie);

    bool setInfo(istream& line);


private:
    // History and hashtable of borrowed movies
    vector<string> history;
    HashTable<string, int, MovieHash> collection;

    // Customer fields - ID & name
    int id;
    string first;
    string last;
};

#endif