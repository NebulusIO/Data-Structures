#include "MyString.h"
#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void)
{
    cout << "Francis Troy Kirinhakone" << endl;

    MyString M_str;

    while(true){
      ///takes in cmd line
      string cmd = "";
      getline(cin, cmd);

      ///separates command from parameters
      string parameter = "";
      parameter = cmd.substr(cmd.find("("));
      parameter = parameter.substr(1, parameter.length()-2);

      if(cmd.find("quit(")==0);

      else if(cmd.find("set(") == 0) {M_str.Set(parameter)};

      else if(cmd.find("substr") == 0) {
        int startIndx;
        int length;

        char* temp_char_str = parameter.c_str();

        startIndx = atoi()
      }

    }

    return 1;
}
