#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream> // cout, cin

using std::cin;
using std::cout;
using std::endl;
using std::ostream;


class Rational
{
	// friend function - non member - makes the << implementation more efficient
	friend ostream & operator<< (ostream &lhs, Rational &rhs);

	public:
		Rational (int newNumerator = 0, 
			      int newDenominator = 1);
	
		//Rational (Rational &copy); // shallow copy
		Rational (Rational &copy); 

		~Rational ();

		Rational & operator= (Rational &rhs); // overloaded assignment
		
		// getters
		int getNumerator (void) const; // constant function - can't modify data members
		int getDenominator (void) const;

		// setters
		void setNumerator (const int newNumerator);
		void setDenominator (const int newDenominator);

		//bool operator< ();

	private:
		int mNumerator;
		int mDenominator;

};

// non-member function
bool operator< (Rational &lhs, Rational &rhs);
bool operator> (Rational &lhs, Rational &rhs);
//bool operator< (double &lhs, Rational &rhs);

#endif