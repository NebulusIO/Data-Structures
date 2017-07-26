#include "rational.h"

Rational::Rational() {
	mNum = 0;
	mDen = 1;
}

// we declare the function as const to promise we won't change anything
int Rational::getNum(void) const {
	return mNum;
}

// we declare the input as const so it can't get modified as we put the data into our class
void Rational::setDen(int const newDen) {
	mDen = newDen;
}

Rational operator+(Rational &lhs, Rational &rhs) {
	int rNum = 0, rDen = 0;
	rNum = lhs.getNum() + rhs.getNum();
	rDen = lhs.getDen() + rhs.getDen();

	Rational result(0, 1);
	result.setNum(rNum);
	result.setDen(rDen);

	return result;
	// we're returning a copy of result, but note that result was declared inside this function, 
	// so potentially dangerous as the function leaves scope
}

// returning a reference means we return the same stream we started with, not a copy
// see below overloaded operator definitions for examples

ostream & operator<<(ostream &output, Rational &rhs) {
	// we want our function to do something like this: 
	// std::cout << mNum << '/' << mDen << std::endl;

	// this is NOT a member function of the Rational class so we must use getters instead
	output << rhs.getNum() << " / " << rhs.getDen() << std::endl;

	return output; // note that output was declared/passed in as a reference to an ostream object
}

istream & operator>>(istream &input, Rational &rhs) {
	int userNum = 0, userDen = 0;

	std::cout << "Please enter the numerator followed by the denominator: ";
	std::cin >> userNum >> userDen;

	// this is NOT a member function of the Rational class so we must use setters
	rhs.setNum(userNum);
	rhs.setDen(userDen);

	return input; // note that inpur was declared/passed in as a reference to an istream object
}