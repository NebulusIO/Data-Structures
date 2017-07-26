#include "mainProgram.h"
#include <iostream>

mainProgram::mainProgram()
{
	//ctor
	//nValues = {10, 50, 100, 500, 1000, 5000, 10000};
}
mainProgram::~mainProgram()
{
	//dtor
}
	
void mainProgram::runProgram()
{
	if (scribe.fileOpener() == 1)
	{
		for (int nValCount = 0; nValCount < 8; nValCount++)
		{
			for (int trialCount = 0; trialCount < 5; trialCount++)
			{
				timeKeeper.runTrial(nValues[nValCount], trialCount);
			}
			timeKeeper.generateAves();
			scribe.entryWriter(timeKeeper.baseTrials, timeKeeper.aveBestTime, timeKeeper.aveWorstTime, timeKeeper.averageTime, nValues[nValCount]);
			timeKeeper.resetValues();
		}
	}
	else
		std::cout << "Error: File failed to open\n";
}
