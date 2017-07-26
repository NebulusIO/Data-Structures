#include <iostream>

using std::ostream;
using std::istream;

class Rational {
	public:
		// default constructor
		Rational();

		// default constructor with default arguments
		Rational(int num1 = 0, int num2 = 1) {
			mNum = num1;
			mDen = num2;
		}

		// can't have both this and the above constructor defined because they take the same
		// number, type, and order of arguments
		/*Rational(int num, int den) {
			mNum = num;
			mDen = den;
		}*/

		// copy constructor
		Rational(Rational &r) {
			mNum = r.mNum;
			mDen = r.mDen;
		}

		// overloaded assignment operator
		// note this is declared inside of the class declaration so it is a member function
		// we only pass in the righthand side operand because the lefthand side is the 
		//     object calling the overloaded assignment operator function
		Rational & operator=(const Rational &rhs) 
		{
			mNum = rhs.mNum;
			mDen = rhs.mDen;
			return *this;
			// the this pointer is a pointer to the current object we are in, which is the object 
			//     calling the overloaded assignment operator function in this case
			// the this pointer is therefore a Rational * pointer, so to return a Rational object, 
			//     we must dereference it first
		}

		// getters (accessors)
		int getNum(void) const;
		int getDen(void) const {
			return mDen;
		}

		// setters (mutators)
		void setNum(int const newNum) {
			mNum = newNum;
		}
		void setDen(int const newDen);

	private:
		int mNum;
		int mDen;
};

// remember that operators such as +, -, <<, >>, etc. are binary operators
// this means that they take in two operands, which become the arguments below
//     by default the left operand becomes the left/first argument, and the 
//     right operand becomes the right/second/last argument

// these are NOT a part of the Rational class
Rational operator+(Rational &lhs, Rational &rhs);
ostream & operator<<(ostream &output, Rational &rhs);
istream & operator>>(istream &input, Rational &rhs);