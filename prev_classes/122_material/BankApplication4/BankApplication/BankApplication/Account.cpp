///////////////////////////////////////////////////////////////////////////////
/// \file         Account.cpp
/// \author       Andrew S. O'Fallon
/// \date         
/// \brief        This application performs basic banking operations.
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////

#include "Account.h"

Account::Account ()
{
	mAccountNumber = 0; // can access private data members directly
	mBalance = 0.0;
	mName = "";
	mCreatedDate = "";
}

Account::Account (int newID, double newBalance, string newName, 
			     string newDate)
{
	mAccountNumber = newID; // can access private data members directly
	
	if (newBalance >= 0.0)
	{
		mBalance = newBalance;
	}
	else
	{
		mBalance = 0.0;
	}
	mName = newName;
	mCreatedDate = newDate;
}

// invoked when passing-by-value
Account::Account (Account &copy)
{
	mAccountNumber = copy.mAccountNumber;
	mName = copy.mName;
	mBalance = copy.mBalance;
	mCreatedDate = copy.mCreatedDate;
}

Account::~Account ()
{
	cout << "inside destructor for Account class" << endl;
}

void Account::credit (double &amount)
{
	mBalance += amount;
}

double Account::getBalance ()
{
	return mBalance;
}

int Account::getAccountNumber ()
{
	return mAccountNumber;
}

string Account::getName ()
{
	return mName;
}

string Account::getDate ()
{
	return mCreatedDate;
}

void Account::setBalance (double newBalance)
{
	mBalance = newBalance;
}

void Account::setAccountNumber (int newAccountNumber)
{
	mAccountNumber = newAccountNumber;
}


void Account::setName (string newName)
{
	mName = newName;
}

void Account::setDate (string newDate)
{
	mCreatedDate = newDate;
}