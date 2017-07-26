// This example illustrates how to work
// with templated functions!

// Templated functions provide a generic
// structure from which the compiler can
// generate specifics based on
// actual arguments. Recall, templated functions must be defined
// in a .h file.

#include "template.h"

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

//int addInt (int a, int b);
//double addDouble (double a, double b);
//string addString (string a, string b);

int main (void)
{
	string s1 = "two";
	string s2 = "strings";

	cout << "result: " << add (s1, s2) << endl;
	return 0;
}

//int addInt (int a, int b)
//{
//	int result = a + b;
//
//	return result;
//}
//
//double addDouble (double a, double b)
//{
//	return a + b;
//}
//
//string addString (string a, string b)
//{
//	return a + b;
//}