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
public:
    // constructor and Destructor
    Comedy();
    Comedy(const string director, const string title, int year);

    // Overloaded Comparison operator
    bool operator<(const Movie& other) const;

    // setData function used by parser
    void setInfo(istream& line);

    string hash();
    char type = 'F';
protected:
    ostream& print(ostream& out) const;
};

#endif