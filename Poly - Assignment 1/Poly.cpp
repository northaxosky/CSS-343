// Poly.cpp
// Kuzey Gok
// CSS 343 - Poly Assignment

#include "Poly.h"

using namespace std;

// ====== Overloaded << and >> Operators ======

// Overloaded << Operator
// Prints the polynomial
ostream &operator<<(ostream &out, const Poly &poly) {

    // boolean value that states if the polynomial is valid or just zeroes
    bool valid = false;
    
    for (int i = poly.size - 1; i >= 0; i--)    {
        
        if (poly.coEffPtr[i] != 0)  {
            valid = true;
            out << " ";

            if (poly.coEffPtr[i] > 0)
                out << "+";
            
            out << poly.coEffPtr[i];

            if (i != 0 && i != 1)
                out << "x^" << i;

            if (i == 1)
                out << "x";
        }
    }

    if (valid)
        return out;
    else
        return out << "0";
}

// Overloaded >> operator
// Sets first input to co-efficient and next one to power
istream &operator>>(istream &in, Poly &poly)    {
    int co;
    int power;
    bool valid;

    while (valid)   {
        in >> co >> power;

        if (co == -1 && power == -1)
            break;

        poly.setCo(co, power);
    }

    return in;
}

// ====== Constructors and Deconstructors ====== 

// Default Constructor
// Takes in no parameters and creates a Poly
Poly::Poly()    {
    this->size = 1;
    coEffPtr = new int[this->size];
    coEffPtr[0] = 0;
}

// Co-eff Constructor
// Takes int co-efficient parameter and creates a Poly
Poly::Poly(int co)  {
    this->size = 1;
    coEffPtr = new int[this->size];
    coEffPtr[0] = co;
}

// Co-eff & Power Constructor
// Takes int co-efficient & int power and creates a Poly
Poly::Poly(int co, int power)   {
    this->size = power++;
    coEffPtr = new int[this->size];
    coEffPtr[0] = co;
}

// Copy Constructor
// Creates a copy of the poly that is taken as a parameter
Poly::Poly(const Poly &poly)    {
    this->size = poly.size;
    coEffPtr = new int[this->size];

    for (int i = 0; i < this->size; i++)    {
        coEffPtr[i] = poly.coEffPtr[i];
    }
}

// Deconstructor
// Deletes the co efficient array pointer
Poly::~Poly()   {
    delete[] coEffPtr;
}

// ====== Overloaded Assignment Operator ======

// Overloaded = Operator
// Assigns the given poly to the current poly
Poly& Poly::operator=(const Poly &poly) {
    if (this->coEffPtr == poly.coEffPtr)
        return *this;

    this->coEffPtr = poly.coEffPtr;
    this->size = poly.size;
}

// ====== Overloaded Comparison Operators ======

// Overloaded == Operator
// Checks if two polys are identical
bool Poly::operator==(const Poly &poly) const   {
    if (this->size != poly.size)    {
        return false;
    }

    for (int i = 0; i < this->size; i++)    {
        if (this->coEffPtr[i] != poly.coEffPtr[i])
            return false;
    }

    return true;
}

// Overloaded != Operator
// Checks if two polys contain any difference
bool Poly::operator!=(const Poly &poly) const   {
    return !(*this == poly);
}

// ====== Overloaded Mathematical Operators ======

// Overloaded + Operator
// Adds the passed in poly to the given poly and returns the new poly
Poly Poly::operator+(const Poly &poly) const   {
    
    if (this->size > poly.size) { // if the left polynomial is larger
        Poly sum(0, this->size);

        for (int i = 0; this->size; i++)    {
            sum.coEffPtr[i] = this->coEffPtr[i];

            if (i < poly.size)  {
                sum.coEffPtr[i] += poly.coEffPtr[i];
            }
        }

        return sum;
    } 

    else    { // if the right polynomial is larger
        Poly sum(0, poly.size);

        for (int i = 0; poly.size; i++) {
            sum.coEffPtr[i] = poly.coEffPtr[i];

            if (i < this->size) {
                sum.coEffPtr[i] += this->coEffPtr[i];
            }
        }

        return sum;
    }
}

// Overloaded - Operator
// Subtracts the passed in poly from the given poly and returns the new poly
Poly Poly::operator-(const Poly &poly) const    {

    if (this->size > poly.size) {   // if the left polynomial is larger
        Poly result(0, this->size);

        for (int i = 0; i < this->size; i++)    {
            result.coEffPtr[i] = this->coEffPtr[i];

            if (i < poly.size)  {
                result.coEffPtr[i] -= poly.coEffPtr[i];
            }
        }

        return result;
    }

    else    { // if the right polynomial is larger
        Poly result(0, poly.size);

        for (int i = 0; i < poly.size; i++) {
            result.coEffPtr[i] = poly.coEffPtr[i];

            if (i < this->size) {
                result.coEffPtr[i] -= poly.coEffPtr[i];
            }
        }

        return result;
    }
}

// Overloaded * Operator
// Multiplies the two polys and returns the new poly
Poly Poly::operator*(const Poly &poly) const    {

    int size = this->size + poly.size - 2;

    Poly result(0, size);

    for (int i = 0; i < this->size; i++) {
        if (this->coEffPtr[i] != 0) {
            for (int j = 0; j < poly.size; j++) {
                result.coEffPtr[i + j] += this->coEffPtr[i] * poly.coEffPtr[j];
            }
        }
    }

    return result;
}

// ====== Overloaded Assignment Operators ======

// Overloaded += operator
// Adds the right poly to the left poly
Poly& Poly::operator+=(const Poly &poly)    {
    *this = *this + poly; // using overloaded + operator
    return *this;
}

// Overloaded -= Operator
// Subtracts the right poly from the left poly
Poly& Poly::operator-=(const Poly &poly)    {
    *this = *this - poly; // using overloaded - operator
    return *this;
}

// Overloaded *= Operator
// Multiplies the two polys
Poly& Poly::operator*=(const Poly &poly)    {
    *this = *this * poly; // using overloaded * operator
    return *this;
}

// ====== Get and Set methods for the co-efficient ======

// Gets the coefficient at the power index and returns 0 if out of range
int Poly::getCo(int power) const    {
    if (power < this->size && power >= 0)   
        return coEffPtr[power];
    else    
        return 0;
}

// Sets co-efficient passed in to the power index of the array
void Poly::setCo(int co, int power)  {
    if (power >= 0) {
        if (power < this->size) this->coEffPtr[power] = co;
        else    {
            int *temp = new int[power + 1];

            for (int i = 0; i < power + 1; i++)    {
                if (i < this->size) temp[i] = this->coEffPtr[i];
                else temp[i] = 0;
            }

            temp[power] = co;

            delete[] this->coEffPtr;
            coEffPtr = temp;
            this->size = power + 1;
        }
    }
}