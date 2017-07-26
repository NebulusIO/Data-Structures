#include <iostream>
#include <string>
#include <cstdlib>

#include "BankManager.h"

using std::cin;
using std::cout;
using std::endl;
using std::string;

class TestBankManager
{
	public:
		void testCredit (void)
		{
			
			mBank.mFirstAccount.setBalance (100);
			double newBalance = 0.0, creditAmount = 5.0;
			mBank.mFirstAccount.credit (creditAmount);
			newBalance = mBank.mFirstAccount.getBalance ();
			if (newBalance == 105)
			{
				cout << "test passed" << endl;
			}
			else
			{
				cout << "test failed" << endl;
			}


		}

	private:
		BankManager mBank;
};