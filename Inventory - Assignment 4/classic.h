// Kuzey Gok
// CSS 343
// Classic Class Header
// Classic extends movies and provides overloaded constructors, destructors,
// comparison operators, and additional fields for the major actor and release month.
#ifndef CLASSIC_ASS_4
#define CLASSIC_ASS_4
#include "movie.h"
#include <iostream>
#include <string>
using namespace std;

class Classic : public Movie   {
public:
    // Constructor & Destructor
    Classic();
    Classic(const Classic& other);
    Classic(string director, string title, string actor, int month, int year);
    ~Classic();

    // Overloaded Comparison Operators
    bool operator<(const Movie& other) const;
    bool operator>(const Movie& other) const;
    bool operator==(const Movie& other) const;
    bool operator!=(const Movie& other) const;

    // overloaded << operator
    friend ostream& operator<<(ostream& out, const Classic& classic);
protected:
    // Classic movies - extra month and major actor
    string actor;
    int month;
};

#endif
