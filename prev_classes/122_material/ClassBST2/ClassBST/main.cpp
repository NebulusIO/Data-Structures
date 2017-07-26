// This project will define a BST container class; will use this class with another class we created (Rational)

#include <iostream>
#include <string>
#include <fstream>

#include "BST.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::ifstream; //in file stream
using std::ofstream; // out file stream
using std::ios; // ??

int main (void)
{
	Rational r1(5, 3), r2(5, 2), r3(5, 4);
	BST t;

	t.insert(r1);
	t.insert(r2);
	t.insert(r3);


	// cin - read from keyboard >>
	// cout - write to display <<

	ifstream input;
	//ofstream output;
	string s;

	s.c_str(); // std::string to c string


	input.open("classList.csv", ios::in);

	char line[100];

	while (!input.eof())
	{
		//input >> line; //takes a char from input file stream and appends to line
		input.getline(line, 100, ','); // splits stream into a new line after delimiter
		cout << "line: " << line << endl;
	}

	return 0;
}