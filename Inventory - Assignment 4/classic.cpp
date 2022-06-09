// Kuzey Gok
// CSS 343
// Classic Class Header
// Classic extends movies and provides overloaded constructors, destructors,
// comparison operators, and additional fields for the major actor and release month.
#include "classic.h"

// Constructor
Classic::Classic() : Movie() {
    actor = "";
    month = 0;
}

//Constructor given all variables
Classic::Classic(string director, string title, string actor, int month, int year)  {
    this->director = director;
    this->title = title;
    this->actor = actor;
    this->month = month;
    this->year = year;
}

string Classic::hash() {
    if (hashKey.length() == 0)  {
        hashKey = to_string(month) + " " + to_string(year) + " " + actor;
    }
    return hashKey;
}

void Classic::setInfo(istream& line) {
    Movie::setInfo(line);
    string temp;
    getline(line, temp);
    vector<string> components = split(temp, ' ');
    actor = components[0] + " " + components[1];
    month = stoi(components[2]);
    year = stoi(components[3]);
}

vector<string> Classic::split(const string& s, char l)  {
    vector<string> tokens;
    string token;
    istringstream tokenStream(s);
    while (getline(tokenStream, token, l))
        tokens.push_back(token);
    return tokens;
}

// overloaded operators
bool Classic::operator<(const Movie& other) const  {
    bool comparison = Movie::operator<(other);
    try {
        const Classic& c = static_cast<const Classic&>(other);
        return (
            comparison &&
            year < c.year &&
            actor < c.actor &&
            month < c.month
        );
    } catch (const bad_cast&e)  {
        return comparison;
    }
    return false;
}


bool Classic::operator==(const Movie& other) const  {
    bool comparison = Movie::operator==(other);
    try {
        const Classic& c = static_cast<const Classic&>(other);
        return (
            comparison &&
            actor == c.actor
        );
    }   catch (const bad_cast& e)   {
            return comparison;
    }
    return comparison;
}

ostream& Classic::print(ostream& out) const{
    Movie::print(out);
    out << ", " << actor << ", " << month << " " << year;
    return out;
}

