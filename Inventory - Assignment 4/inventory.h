#ifndef INV_ASS_4
#define INV_ASS_4
#include "movie.h"
#include "hashtable.h"
#include <vector>

class Inventory {
public:
    Inventory();
    ~Inventory();

    void add(Movie* movie);
    Movie* find(string);

private:
    HashTable<string, Movie*> movies;
};

#endif