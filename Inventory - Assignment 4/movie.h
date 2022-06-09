// Kuzey Gok
// CSS 343
// Movie Class Header
// The movie class is the general implementation of a movie that
// is extended on by specific movie genres. It has constructors, destructor,
// multiple get and set functions, along with overloaded comparison operator
// functions. It has the private fields of name, director, and year. These fields
// are all common throughout all genres of movies.
#ifndef MOVIE_ASS_4
#define MOVIE_ASS_4
#include <iostream>
#include <string>

using namespace std;

class Movie {
public:
    // Constructor and Destructors
    Movie();
    Movie(const Movie& other);
    Movie(const string& name, const string& director, int year);
    virtual ~Movie();

    // Get functions
    string getDirector() const;
    string getTitle() const;
    string getDate() const;
    string getAll() const;

    // Set functions
    void setDirector(string director);
    void setTitle(string title);
    void setDate(string date);

    // overloaded functions
    virtual bool operator<(const Movie& other) const;
    virtual bool operator>(const Movie& other) const;
    virtual bool operator==(const Movie& other) const;
    virtual bool operator!=(const Movie& other) const;

    virtual friend ostream& operator<<(ostream& out, const Movie& mov);

protected:
    // Private fields of movies
    string director;
    string title;
    int year;
};

#endif