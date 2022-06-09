#include "inventory.h"
const int MAX_TYPES = 10;

Inventory::Inventory()  {
    typeMovies = 3;
    for (unsigned int i = 0; i < MAX; i++)  {
        sort[i] = 0;
        for (unsigned int j = 0; i < sort[i]; j++)  {
            sortedMovies[i][j] = nullptr;
        }
    }
}

Inventory::~Inventory() {
    for (unsigned int i = 0; i < MAX; i++)  {
        for (unsigned int j = 0; j < sort[i]; j++)  {
            if (sortedMovies[i][j]) {
                delete sortedMovies[i][j];
            }
        }
    }
}

void Inventory::add(Movie* movie)   {
    if (movie)  {
        movies.insert(movie->hash(), movie);
        insert(movie);
    }
}

Movie* Inventory::find(string key)  {
    Movie* movie = nullptr;
    movies.retrieve(key, movie);
    return movie;
}

int Inventory::idx(Movie* movie)    {
    char type = movie->type;
    if (type == 'F')
        return 0;
    if (type == 'D')
        return 1;
    if (type == 'C')
        return 2;
    else    {
        cout << "Movie Type is not supported: " << type; 
    
    }
    return -1;
}

void Inventory::insert(Movie* movie)    {
    int index = idx(movie);
    if (index < 0)
        return;
    int temp = 0;
    while ((temp < sort[index]) && *sortedMovies[index][temp] < *movie)   {
        temp++;
    }

    if (temp < sort[index]) {
        for (int i = sort[index]; i > temp; i--)    {
            sortedMovies[index][i] = sortedMovies[index][i - 1];
        }
    }
    sort[index]++;
    sortedMovies[index][temp] = movie;
}

ostream& operator<<(ostream& out, const Inventory& inventory)   {
    inventory.print(out);
    return out;
}

ostream& Inventory::print(ostream& out) const {
    for (unsigned int i = 0; i < typeMovies; i++)   {
        for (unsigned int j = 0; j < sort[i]; j++)  {
            out << *sortedMovies[i][j] << endl;
        } 
    }
    return out;
}
