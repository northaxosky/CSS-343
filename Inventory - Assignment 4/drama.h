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
    Drama(const string director, const string title, const int year);

    // Overloaded comparison operators
    bool operator<(const Movie& other) const;

    // setData function used by parser
    void setInfo(istream& line);

    string hash();
    char type = 'D';
protected:
    ostream& print(ostream& out) const;
};

#endif