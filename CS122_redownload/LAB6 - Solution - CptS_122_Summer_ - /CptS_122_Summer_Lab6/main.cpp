#include "rational.h"

int main(void) {
	Rational r1(0, 1);
	int num1 = 5, num2 = 7;
	Rational r2(num1, num2);
	Rational r3(r2); // this will invoke the copy constructor

	r1 = r2;

	r1 = r2 + r3;

	std::cin >> r3;

	std::cout << "r1: " << r1;

	return 0;
}