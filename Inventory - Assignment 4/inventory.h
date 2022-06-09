// Kuzey Gok
// CSS 343
// Inventory Class
// The inventory class is used to keep track of movies that the shop
// currently has in its stock.
#ifndef INV_ASS_4
#define INV_ASS_4
#include "movie.h"
#include "hashtable.h"
#include <vector>

const int MAX = 5;

class Inventory {
    friend ostream& operator<<(ostream& out,const Inventory& inv);
public:
    // Constructor and Destructor
    Inventory();
    ~Inventory();

    // add and find movie functions
    void add(Movie* movie);
    Movie* find(string key);

private:
    void insert(Movie* movie);
    int idx(Movie* movie);
    ostream& print(ostream& out) const;
    // Hash Table to keep track of movies
    HashTable<string, Movie*, MovieHash> movies;
    int sort[MAX];
    Movie* sortedMovies[MAX][100];
    int typeMovies;
};

#endif