///////////////////////////////////////////////////////////////////////////////
/// \file         BankManager.cpp
/// \author       Andrew S. O'Fallon
/// \date         
/// \brief        This application performs basic banking operations.
///           
///       
/// REVISION HISTORY:
/// \date  
///            
///////////////////////////////////////////////////////////////////////////////

#include "BankManager.h"


void BankManager::edit (Account newAccount)
{
	mFirstAccount.setBalance (newAccount.getBalance ());
	mFirstAccount.setAccountNumber (newAccount.getAccountNumber ());
	// should call the getters for the other two attributes
}

// adding to the balance
double BankManager::credit (double &amount)
{
	mFirstAccount.credit (amount); // don't be confused between credit functions
	return mFirstAccount.getBalance ();
}
