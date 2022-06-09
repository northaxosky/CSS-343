// Kuzey Gok
// CSS 343
// Classic Class Header
// Classic extends movies and provides overloaded constructors, destructors,
// comparison operators, and additional fields for the major actor and release month.
#include "classic.h"

// Constructor
Classic::Classic()  {
    actor = "";
    month = 0;
}

// Copy Constructor
Classic::Classic(const Classic& other)  {
    this->director = other.director;
    this->title = other.title;
    this->actor = other.actor;
    this->month = other.month;
    this->year = other.year;
}

//Constructor given all variables
Classic::Classic(string director, string title, string actor, int month, int year)  {
    this->director = director;
    this->title = title;
    this->actor = actor;
    this->month = month;
    this->year = year;
}

// Overloaded outstream operator
ostream& operator<<(ostream& out, const Classic& classic) {
    cout << "Name: " << classic.title << endl; 
    cout << "Director: " << classic.director << endl;
    cout << "Major Actor: " << classic.actor << endl;
    cout << "Release Date: " << classic.month << " " << classic.year << endl;
}