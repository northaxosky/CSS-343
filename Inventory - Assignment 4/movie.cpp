#include "movie.h"

Movie::Movie()  {
    director = "";
    title = "";
    stock = 0;
    year = -1;
}

Movie::Movie(const string name, const string director, int year)    {
    this->director = director;
    this->title = name;
    this->year = year;
    this->stock = 0;
}

bool Movie::updateStock(int num)    {
    if (num < 0 && stock <= 0)  {
        stock = 0;
        return false;
    }
    stock += num;
    return true;
}

ostream& operator<<(ostream& out, const Movie& movie)   {
    movie.print(out);
    return out;
}

ostream& Movie::print(ostream& out) const {
    out << type << ", " << stock << ", " << director << ", " << title;
    return out;
}

void Movie::setInfo(istream& line) {
    string temp;
    getline(line, temp, ',');
    stock = stoi(temp);
    getline(line, temp, ',');
    temp.pop_back();
    director = temp;
    getline(line, temp, ',');
    temp.pop_back();
    title = temp;
}

// overloaded operators
bool Movie::operator<(const Movie& other) const  {
    return type < other.type;
}

bool Movie::operator>(const Movie& other) const  {
    return type > other.type;
}

bool Movie::operator==(const Movie& other) const  {
    return (type == other.type && year == other.year &&
            title == other.title && director == other.director);
}

bool Movie::operator!=(const Movie& other) const  {
    return !(*this == other);
}
