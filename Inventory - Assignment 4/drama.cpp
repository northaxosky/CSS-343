#include "drama.h"

// Constructor
Drama::Drama() : Movie()    {}

// Copy Constructor
Drama::Drama(const Drama& other) : Movie(other) {}

// Constructor given parameters
Drama::Drama(const string director, const string title, const int year) 
: Movie(title, director, year)  {}
