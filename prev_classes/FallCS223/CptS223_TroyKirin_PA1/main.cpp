/*
Troy Kirin
CptS_223
PA_1
*/

#include <iostream>
#include "bubblesort.h"
#include "dataGenerator.h"
#include "fileWriter.h"
#include "trialController.h"
#include "mainProgram.h"

using namespace std;

int main()
{
	srand(unsigned(time(0))); //for random numbers generated throughout program

	cout << "Started randomizing numbers!" << endl;

	mainProgram master;
	cout << "Running program." << endl;
	master.runProgram();

	cout << "The program has compiled!\n" << endl << "Check .csv file to see results." << endl;
    return 0;
}
