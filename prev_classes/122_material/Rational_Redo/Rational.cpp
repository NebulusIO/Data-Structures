#include "Rational.h"

Rational::Rational()
{
    //ctor

}

Rational::~Rational()
{
    //dtor
}

Rational::Rational (int newNumerator, int newDenominator)
{
    Rational::mNumerator = newNumerator;
    Rational::mDenominator = newDenominator;


}

Rational::Rational(Rational &copy) //shallow copy
{
    Rational::mNumerator = copy.mNumerator;
    Rational::mDenominator = copy.mDenominator;
}



Rational & Rational::operator= (Rational &rhs) //overloaded assignment operator
{
    if(this != &rhs) //check for self-assignment
    {
        this->mNumerator = rhs.mNumerator;
        mDenominator = rhs.mDenominator;
    }
    return *this;
}


////////////////////////////////////////////////////////////

//getters
int Rational::getDenominator(void) const
{
    return Rational::mDenominator;
}

int Rational::getNumerator(void) const
{
    return Rational::mNumerator;
}

//setters

void Rational::setNumerator(const int newNumerator)
{
    this->mNumerator = newNumerator;
}

void Rational::setDenominator(const int newDenominator)
{
    this->mDenominator = newDenominator;
}

////////////////////////////////////////////////////////////

//non-memberfunctions

bool operator< (Rational &lhs, Rational &rhs)
{
    return(lhs.getNumerator()*rhs.getDenominator()<
            rhs.getNumerator() * lhs.getDenominator());
}
bool operator> (Rational &lhs, Rational &rhs)
{
    return (lhs.getNumerator() * rhs.getDenominator() >
            rhs.getNumerator() * lhs.getDenominator());
}

ostream & operator << (ostream &lhs, Rational &rhs)
{
    lhs << rhs.mNumerator << " / " << rhs.mDenominator;

    return lhs;
}
