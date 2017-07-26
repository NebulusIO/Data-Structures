///////////////////////////////////////////////////////////////////////////////
/// \file         Account.h
/// \author       Andrew S. O'Fallon
/// \date         
/// \brief        This application performs basic banking operations.
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////

#ifndef ACCOUNT_H
#define ACCOUNT_H

#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;
using std::string;

// our first class
class Account
{
	public:
		// constructor - initialize the private data members of the class
		Account (); // default constructor
		// function overloading
		Account (int newID, double newBalance, string newName, 
			     string newDate);

		// copy constructor - invoked when passing-by-value
		Account (Account &copy); // pass-by-reference

		// destructor - implicitly invoked when an object 
		// goes out of scope
		~Account ();

		// setters - mutators
		void setBalance (double newBalance);
		void setAccountNumber (int newAccountNumber);
		void setName (string newName);
		void setDate (string newDate);

		void credit (double &amount);


		// getters - accessors
		double getBalance ();
		int getAccountNumber ();
		string getName ();
		string getDate ();

	private:
		// data members - attributes
		double mBalance;
		int mAccountNumber;
		string mName;
		string mCreatedDate;
};


#endif