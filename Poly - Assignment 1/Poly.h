// Poly.h
// Kuzey Gok
// CSS 343 - Poly Assignment
//
// Implementation of polynomials

#ifndef ASS1_POLY_H
#define ASS1_POLY_H

#include <iostream>

using namespace std;

class Poly  {
private:

    // Pointer to array and size of array
    int* coEffPtr;
    int size; 

    // Overloaded << and >> operators
    // << Displays the polynomial
    // >> Takes two ints for coeff and power and puts into array
    friend ostream &operator<<(ostream &out, const Poly &poly);
    friend istream &operator>>(istream &in, Poly &poly);

public:
    // Constructors
    Poly();
    Poly(int co);
    Poly(int co, int power);
    Poly(const Poly &poly);

    // Deconstructor
    ~Poly();

    // Overloaded assignment operator
    Poly& operator=(const Poly &poly);

    // Overloaded comparison operators
    bool operator==(const Poly &poly) const;
    bool operator!=(const Poly &poly) const;

    // Overloaded Mathematical operators
    Poly operator+(const Poly &poly) const;
    Poly operator-(const Poly &poly) const;
    Poly operator*(const Poly &poly) const;
    
    // Overloaded assignment operators
    Poly& operator+=(const Poly &poly);
    Poly& operator-=(const Poly &poly);
    Poly& operator*=(const Poly &poly);

    // get and set for coefficient
    int getCo(int power) const;
    void setCo(int co, int power);

};

#endif // ASS1_POLY_H