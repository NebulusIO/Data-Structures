#include "MyString.h"

#include <iostream>
#include <string>
#include <fstream>

using namespace std;

int main(void)
{
    cout << "Francis Troy Kirinhakone, 11429784" << endl;

    //create MyString to work with
    MyString mainString;

    while(true)
    {
        string cmd;
        getline(std::cin, cmd);

        //finds and assigns the parameters to c_str_par
            string parameter = "";
            parameter = cmd.substr(cmd.find("("));
            parameter = parameter.substr(1, parameter.length()-2);
        //
        char *c_str_par = new char;
        strcpy(c_str_par, parameter.c_str());
        //


        if(cmd.find("quit()") == 0) {break;} //breaks cmd loop and returns Done

        else if (cmd.find("set(") == 0){ //sets stringBeingUsed with input paramaters
           mainString.Set(c_str_par);
        }

        else if(cmd.find("substr(") == 0) {
            int startIndx = atoi(c_str_par);
            mainString.Substring(startIndx);
        }

        else if(cmd.find("indexof(") == 0) {
            //convert first part of string into char
            string t_str_sub_str = parameter.substr(0, parameter.find(","));
            char* t_char_sub_str = new char;
            strcpy(t_char_sub_str, t_str_sub_str.c_str());

            //convert digits after parenthases into int
            string t_sub_num = parameter.substr(parameter.find(","));
            const char* t_char_num = new char;
            t_char_num = t_sub_num.c_str();
            int t_int_sub_num = atoi(t_char_num);
            //

            mainString.IndexOf(t_char_sub_str, t_int_sub_num);
        }

        else if(cmd.find("bad_char_table(") == 0) {
            //mainString.bad_char_table();
        }

        else if(cmd.find("split(") == 0) {
//            mainString.Split();
        }

        else if(cmd.find("reverse(") == 0 ) {
            mainString.Reverse();
        }

        else if(cmd.find("is_integer(") == 0) {
            mainString.IsInt();
        }

        else if(cmd.find("starts_with(") == 0) {
//           mainString.StartsWith();
        }

        else if(cmd.find("anagrams(") == 0) {
//            mainString.GetAnagrams();
        }

    }

    cout << "Done" << endl;
    return 1;
}
