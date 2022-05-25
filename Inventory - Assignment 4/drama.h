#ifndef DRAMA_ASS_4
#define DRAMA_ASS_4
#include "movie.h"
#include <iostream>
using namespace std;

class Drama : public Movie {
public:
    Drama();
    Drama(const Drama& other);
    Drama(const string director, const string title, const int year);
    ~Drama();

    bool operator<(const Movie& other) const;
    bool operator>(const Movie& other) const;
    bool operator==(const Movie& other) const;
    bool operator!=(const Movie& other) const;
};

#endif