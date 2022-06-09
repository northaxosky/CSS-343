#include "comedy.h"

// Constructor
Comedy::Comedy()  : Movie()   {}

// Constructor given parameters
Comedy::Comedy(string director, string title, int year) : Movie(title, director, year)  {}

string Comedy::hash()  {
    if (hashKey.length() == 0)  {
        hashKey = title + " " + to_string(year);
    }
    return hashKey;
}

void Comedy::setInfo(istream& line) {
    Movie::setInfo(line);
    string temp;
    getline(line, temp, ',');
    year = stoi(temp);
}

bool Comedy::operator<(const Movie &other) const  {
    bool compare = Movie::operator<(other);
    try {
        const Comedy& c = static_cast<const Comedy&>(other);
        return (
            title < c.title &&
            year < c.year
        );
    } catch (const bad_cast& e) {
        return compare;
    }
    return false;
}

ostream& Comedy::print(ostream& out) const  {
    Movie::print(out);
    out << ", " << year;
    return out;
}