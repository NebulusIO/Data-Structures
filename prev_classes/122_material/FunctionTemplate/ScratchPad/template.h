#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// add () is a templated function,
// it currently can apply the "+" operator
// to any type that supports "+"
template <class T>
T add (T a, T b)
{
	return a + b;
}