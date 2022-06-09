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
#include <vector>
#include <istream>
#include <sstream>
using namespace std;

class Classic : public Movie   {
public:
    // Constructor & Destructor
    Classic();
    Classic(string director, string title, string actor, int month, int year);

    // Overloaded Comparison Operators
    bool operator<(const Movie& other) const;
    bool operator==(const Movie& other) const;

    // setData function used by parser
    void setInfo(istream& line);

    string hash();
    char type = 'C';
protected:
    // Classic movies - extra month and major actor
    string actor;
    int month;
    ostream& print(ostream& out) const;

    vector<string> split(const string& s, char l);
};

#endif
