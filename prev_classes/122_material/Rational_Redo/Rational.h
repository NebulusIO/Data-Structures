#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream> // cout , cin

using std::cin;
using std::cout;
using std::endl;
using std::ostream;

class Rational
{
    friend ostream & operator << (ostream &lhs, Rational &rhs);

    public:
        Rational();
        ~Rational();

        Rational (int newNumerator = 0, int newDenominator = 1);

        Rational (Rational &copy); //shallow copy

        Rational & operator= (Rational &rhs); //overloaded assignment operator

        //getters
        int getNumerator (void) const;
        int getDenominator (void) const;

        //setters
        void setNumerator (const int newNumerator);
        void setDenominator (const int newDenominator);


    private:
        int mNumerator;
        int mDenominator;

    protected:

};

//non-member function
bool operator< (Rational &lhs, Rational &rhs);
bool operator> (Rational &lhs, Rational &rhs);
//bool operator< (double &lhs, Rational &rhs);

#endif
