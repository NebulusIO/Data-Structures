/*
Francis Troy Kirinhakone 11429784
HW 0
CptS 223 - Advanced Data Structures
Evan Olds Summer 2017
June 7, 2017
*/

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void)
{
    cout << "Francis Troy Kirinhakone, 11429784" << endl;

    while(true)
    {
        string line;
        getline(std::cin, line);


        if(line.find("quit()") == 0)
            break;

        else
        {
            string name;
            string parameter;
            int paraBegin;
            int paraEnd;
            int paraLen;

            paraBegin = line.find("(");
            paraEnd = line.find(")");

            name = line.substr(0, line.find("("));
            parameter = line.substr(line.find("("));
            paraLen = parameter.length();
            parameter = parameter.substr(1, paraLen-2);
            /*paraBegin = line.find("(");
            paraEnd = line.find("nullptr");
            paraBegin++;
            paraEnd-3;
            parameter = line.substr(paraBegin, paraEnd);
            */

            cout << "Name: " << name << endl;
            cout << "Parameters: " << parameter << endl;
        }
    }

    cout << "Done" << endl;
    return 1;
}


