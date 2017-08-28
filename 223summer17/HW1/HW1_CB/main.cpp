//Francis Troy Kirinhakone
//11429784
//CS223 - Summer2017
//HW1

#include "reverse_stack.h"
#include <iostream>
#include <string>
#include <sstream>

using std::string;
using std::cin;
using namespace std;

int main(void)
{
    RevStack *aStack;

	cout << "Francis Troy Kirinhakone, 11429784" << endl;

	while(true)
	{
        cout << "Please enter command: ";

        string cmd;
        string numberstr;
        int input;
        getline(cin,cmd);

        numberstr = cmd.substr(cmd.find("("));
        int numstrlen = numberstr.find(")");
        numberstr = numberstr.substr(1, numstrlen-1);
        istringstream buffer(numberstr);
        buffer >> input;

        if (cmd.find("push(") == 0)
            {
            cout << "entered push() input val is: " << input << endl;
            aStack->Push(input);
            }
        else if (cmd.find("pop(") == 0) { aStack->Pop(); }
        else if (cmd.find("display(") == 0) { aStack->Display(); }
        else if (cmd.find("reverse(") == 0) { aStack->Reverse(); }
        else if (cmd.find("isempty(") == 0) { aStack->IsEmpty(); }
        else if (cmd.find("quit()") == 0) { break; }
	}

	cout << "Done" << endl;

return 1;

}
