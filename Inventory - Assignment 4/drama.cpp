#include "drama.h"

// Constructor
Drama::Drama() : Movie() {}

// Constructor given parameters
Drama::Drama(const string director, const string title, const int year) 
: Movie(title, director, year)  {}

string Drama::hash()    {
    if (hashKey.length() == 0)
        hashKey = director + " " + title;
    return hashKey;
}

void Drama::setInfo(istream& line)  {
    Movie::setInfo(line);
    string temp;
    getline(line, temp, ',');
    year = stoi(temp);
}

bool Drama::operator<(const Movie& other) const {
    bool compare = Movie::operator<(other);
    try {
        const Drama& d = static_cast<const Drama&>(other);
        return (
            director < d.director &&
            title < d.title
        );
    } catch (const bad_cast& e) {
        return compare;
    }
    return false;
}

ostream& Drama::print(ostream& out) const   {
    Movie::print(out);
    out << ", " << year;
    return out;
}