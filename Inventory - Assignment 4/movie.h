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
#include <sstream>
#include <istream>
using namespace std;

class Movie {
    // Overloaded cout function
    friend ostream& operator<<(ostream& out, const Movie& movie);
public:
    // Constructor and Destructors
    Movie();
    Movie(const string name, const string director, int year);
    virtual ~Movie() = default;

    // Get functions
    string getDirector() const { return director; }
    string getTitle() const { return title; }
    int getDate() const { return year; }
    int getStock() const { return stock; }

    // Set functions
    void setDirector(string director);
    void setTitle(string title);
    void setDate(string date);

    bool updateStock(int num);

    // overloaded functions
    virtual bool operator<(const Movie& other) const;
    virtual bool operator>(const Movie& other) const;
    virtual bool operator==(const Movie& other) const;
    virtual bool operator!=(const Movie& other) const;


    // setData function used by parser
    void setInfo(istream& line);

    virtual string hash() { return title; }


    char type = 'X';
protected:
    virtual ostream& print(ostream& out) const;
    // Private fields of movies
    string director;
    string title;
    int year;
    int stock;
    string hashKey = "";
};

#endif