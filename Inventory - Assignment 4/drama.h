// Kuzey Gok
// CSS 343
// Drama Class Header
// The drama class is extended from the movie class and provides overloaded
// constructors, destructor, and comparison operators.
#ifndef DRAMA_ASS_4
#define DRAMA_ASS_4
#include "movie.h"
#include <iostream>
using namespace std;

class Drama : public Movie {
public:
    // Constructors and Destructor
    Drama();
    Drama(const Drama& other);
    Drama(const string director, const string title, const int year);
    ~Drama();

    // Overloaded comparison operators
    bool operator<(const Movie& other) const;
    bool operator>(const Movie& other) const;
    bool operator==(const Movie& other) const;
    bool operator!=(const Movie& other) const;
};

#endif