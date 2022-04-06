// Main.cpp
// Kuzey Gok
// CSS 343 - Poly Assignment
// Tests the functionality of the Poly class, extends upon the given lab1.cpp

#include "Poly.h"

using namespace std;

int main() {
	Poly A(5, 7), B(3, 4), C(2), D(A), X, Y;
	Poly A2, B2, Z1, Z2;

	// set polynomials A and B to desired values
	// A = +5x^7 -4x^3 +10x -2
	// B = +3x^4 +1x^3 
	cout << "Enter terms for polynomial A.  Enter a coefficient " << endl
		<< "then exponent for each term. Enter -1 -1 to terminate." << endl;
	cin >> A;                                     // or use a bunch of setCoeff
	cout << "Enter terms for polynomial B.  Enter a coefficient " << endl
		<< "then exponent for each term. Enter -1 -1 to terminate." << endl;
	cin >> B;                                     // or use a bunch of setCoeff
	
	// outputs exactly what is in quotes: "A = +5x^7 -4x^3 +10x -2"
	cout << "A =" << A << endl;
	// outputs exactly what is in quotes: "B = +3x^4 +1x^3"
	cout << "B =" << B << endl << endl;
	

	A2 = A;
	B2 = B;
	C = A + B;
	cout << "Compute C = A + B: " << C << endl << endl;

	cout << ((A == B) ? "A == B" : "A is not == B") << endl;
	cout << ((A != B) ? "A is not == B" : "A == B") << endl << endl;

	Z1 = A2 - B2;
	cout << "Compute  Z1 = A2 - B2: " << Z1 << endl;
	Z2 = B2 - A2;
	cout << "Compute  Z2 = B2 - A2: " << Z2 << endl << endl;

	cout << "Compute  D = A * B - 15" << endl;
	cout << "Before: D =" << D << endl;
	D = A * B - 15;
	cout << "After:  D =" << D << endl << endl;

	cout << "Test assignment operators" << endl;
	X = C = D = D;
	Y += A -= B *= A;
	cout << "X =" << X << endl;
	cout << "Y =" << Y << endl << endl;

	cout << "Get and Set coefficient" << endl;
	int coeff = D.getCo(0);
	cout << "coeff of subscript 0 of D is: " << coeff << endl;
	cout << "Doing getCoeff for term -20000" << endl;
	coeff = D.getCo(-20000);              // handle value out of range
	D.setCo(50, 0);                        // set x^0 coeff to 50
	D.setCo(50, 20000);                    // set x^20000 coeff to 50
	cout << "D =" << D << endl << endl;

	return 0;
}
