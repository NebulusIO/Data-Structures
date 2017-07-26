///////////////////////////////////////////////////////////////////////////////
/// \file         BankManager.h
/// \author       Andrew S. O'Fallon
/// \date         
/// \brief        This application performs basic banking operations.
///           
///       
/// REVISION HISTORY:
/// \date  10/21/14 (created)
///            
///////////////////////////////////////////////////////////////////////////////

#ifndef BANK_MANAGER_H
#define BANK_MANAGER_H

#include <iostream>
#include <string>
#include <cstdlib>

#include "Account.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class BankManager
{
	// Allows for TestBankManager objects to 
	// directly access private data members of BankManager
	// w/o the need for setters and getters
	friend class TestBankManager; 

	public:
		void edit (Account newAccount); // demonstrate copy constructor
		// update
		double credit (double &amount); // pass-by-reference

	private:
		Account mFirstAccount;
};

#endif