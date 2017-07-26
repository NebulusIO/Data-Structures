#include "TestRational.h"

// testing the less than operator (<)
void TestRational::testLT (void)
{
	Rational r1 (5, 3), r2 (10, 7);
	bool result = false;

	result = r1 < r2; // applying the LT operator overloaded for Rational objects

	if (result == false)
	{
		cout << "test passed for < " << endl;
	}
	else
	{
		cout << "test failed for < " << endl;

	}
}