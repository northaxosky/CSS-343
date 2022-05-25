// Kuzey Gok
// CSS 343
// Comedy Class Header
// Comedy class is extended from the movie class and has constructors,
// destructors, and overloaded comparison operators.
#ifndef COMEDY_ASS_4
#define COMEDY_ASS_4
#include <iostream>
#include "movie.h"
using namespace std;

class Comedy : public Movie {
    // constructor and Destructor
    Comedy();
    Comedy(const Comedy& other);
    Comedy(string director, string title, int year);
    ~Comedy();

    // Overloaded Comparison operators
    bool operator<(const Movie& other) const;
    bool operator>(const Movie& other) const;
    bool operator==(const Movie& other) const;
    bool operator!=(const Movie& other) const;
};

#endif