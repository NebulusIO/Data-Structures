
// Francis Troy Kirinhakone, 11429784
// HW #4
// CptS 223 - Advanced Data Structures

#include "SortingAlgorithims.h"

#include <iostream> //std::cout std::endl;
#include <string> //std::string
#include <cstdlib> //std::find;
#include <vector>

using std::cout; using std::endl;
using std::string;
using std::find;

int main (void)
{

//print name
cout << "Francis Troy Kirinhakone, 11429784" << endl;

//create array
SortAlg workArray;;

vector<Item> my_Array;

//stay in command loop until quit() is entered
    while(true)
    {
        string cmd; //command string
        getline(std::cin, cmd);//get character input from terminal and assign to cmd

        //finds and assigns the parameters to c_str_par
            string parameter = ""; //new string "paramater" itilitzed to empty string


            parameter = cmd.substr(cmd.find("("));//substring from first '(' to null terminator
            parameter = parameter.substr(1, parameter.length()-2);//substring from +1 of prev string to -2 of length of string to remove 2nd ')'


        if(cmd.find("quit()") == 0) {break;} //breaks cmd loop and returns Done

        else if(cmd.find("set(") == 0) { //parameter (num1Val,num1Index; ...)
            workArray.Set(parameter);
        }

        else if(cmd.find("insertion(") == 0)
        {
            workArray.insertion();
        }

        else if(cmd.find("shell(") == 0)
        {
            int gap_1, gap_2, gap_3; //initilize gap vals
            string temp_str = ""; //temp string for stoi

            //convert string of gap vals to int vals
            temp_str = parameter.substr(0, parameter.find(","));
            gap_1 = stoi(temp_str);
            parameter = parameter.substr(2);

            temp_str = parameter.substr(0, parameter.find(","));
            gap_2 = stoi(temp_str);
            parameter = parameter.substr(2);

            temp_str = parameter.substr(0, parameter.find(","));
            gap_3 = stoi(temp_str);

            ///testing
            cout << "gaps:" << gap_1 << "," << gap_2 << "," << gap_3 << endl;
            //

            //run shell()
            workArray.shell(gap_1, gap_2, gap_3);


        }

        else if(cmd.find("merge_sort(") == 0)
        {
            workArray.merge_sort();
        }

        else if(cmd.find("partition(") == 0)
        {

        }

        else if(cmd.find("quick_sort(") == 0)
        {
            workArray.quick_sort();
        }

        else if(cmd.find("print(") == 0) {workArray.printArray();}

    }
    return 1;
}
