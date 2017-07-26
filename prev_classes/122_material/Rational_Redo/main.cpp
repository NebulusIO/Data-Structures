#include <iostream>
#include "Rational.h"
#include "TestRational.h"

using namespace std;

int main(void)
{
    TestRational t1;
	t1.testLT ();

	Rational r1 (7,0);
	cout << r1 << endl;
	//Rational r1 (4, 5), r2 (18, 7);

	//r1 = r2; // this is apply the overloaded assignment = that we defined!

	return 0;
}
