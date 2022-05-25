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

    bool operator<(const Movie& other) const;
    bool operator>(const Movie& other) const;
    bool operator==(const Movie& other) const;
    bool operator!=(const Movie& other) const;
private:
    string actor;
    int month;
};

#endif
