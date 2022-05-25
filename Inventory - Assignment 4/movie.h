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
    Movie(string& name, string& director, int year);
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

private:
    string name;
    string director;
    int year;
};

#endif