#include "comedy.h"

// Constructor
Comedy::Comedy() : Movie()    {}

// Copy Constructor
Comedy::Comedy(const Comedy& other) : Movie(other)  {}

// Constructor given parameters
Comedy::Comedy(string director, string title, int year) : Movie(title, director, year)  {}