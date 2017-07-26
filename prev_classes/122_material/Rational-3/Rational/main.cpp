// In this example we will define a value class called Rational. A rational object consists of 
// two numbers in the form: numerator / denominator. We will define the different ways rational
// objects may be compared, so that in the future we may construct a binary search tree of rational objects.

// History: 10/5 - Completed  overloading of >, <, and << for
//                 Rational objects. Also, implemented 1
//                 test case with TestLT ().

#include "Rational.h"
#include "TestRational.h"

int main (void)
{
	TestRational t1;
	t1.testLT ();

	Rational r1 (6, 4);
	cout << r1 << endl;
	//Rational r1 (4, 5), r2 (18, 7);

	//r1 = r2; // this is apply the overloaded assignment = that we defined!

	return 0;
}