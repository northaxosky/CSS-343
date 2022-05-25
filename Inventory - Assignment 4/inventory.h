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

class Inventory {
public:
    // Constructor and Destructor
    Inventory();
    ~Inventory();

    // add and find movie functions
    void add(Movie* movie);
    Movie* find(string);

private:
    // Hash Table to keep track of movies
    HashTable<string, Movie*> movies;
};

#endif