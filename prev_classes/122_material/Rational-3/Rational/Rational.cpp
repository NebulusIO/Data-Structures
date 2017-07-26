#include "Rational.h"

Rational::Rational (int newNumerator, 
			      int newDenominator)
{
	mNumerator = newNumerator;
	mDenominator = newDenominator;
}

Rational::Rational (Rational &copy)
{
	// shallow copy
	mNumerator = copy.mNumerator;
	mDenominator = copy.mDenominator;
}

Rational::~Rational ()
{
	cout << "Inside Rational's Destructor" << endl;
}


// We are overloading the assignment operator (=)
// so that we can assign one Rational object to another
Rational & Rational::operator= (Rational &rhs)
{
	// Really think about what "this" pointer is referring to.
	// "this" stores the address to the object for which
	// the member function (in this case the = function)
	// is called.
	if (this != &rhs) // checking for self-assignment
	{
		mNumerator = rhs.mNumerator; // could have also used this->mNumerator = rhs.numerator
		this->mDenominator = rhs.mDenominator;
	}

	return *this;
}

int Rational::getNumerator (void) const // constant function - can't modify data members
{
	return mNumerator;
}

int Rational::getDenominator (void) const
{
	return mDenominator;
}

		// setters
void Rational::setNumerator (const int newNumerator)
{
	mNumerator = newNumerator;
}
		
void Rational::setDenominator (const int newDenominator)
{
	mDenominator = newDenominator;
}


// non-member function
bool operator< (Rational &lhs, Rational &rhs)
{
	return (lhs.getNumerator () * rhs.getDenominator () < 
		rhs.getNumerator () * lhs.getDenominator ());
}

bool operator> (Rational &lhs, Rational &rhs)
{
	return (lhs.getNumerator () * rhs.getDenominator () > 
		rhs.getNumerator () * lhs.getDenominator ());
}

ostream & operator<< (ostream &lhs, Rational &rhs)
{
	lhs << rhs.mNumerator << " / " << rhs.mDenominator;

	return lhs;

}

