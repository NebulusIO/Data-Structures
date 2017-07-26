#include <iostream> // stdio.h
#include <string>

using std::cout;
using std::endl;
using std::cin;
using std::string;

int main (void)
{
	//cout << "Hello CptS 122!" << endl;

	cout << "Enter a number: ";
	int number = 0;
	cin >> number;
	cout << "number: " << number << endl;

	string make = "Ford";
	make = make + "Model T";
	cout << "make: " << make << endl;

}
