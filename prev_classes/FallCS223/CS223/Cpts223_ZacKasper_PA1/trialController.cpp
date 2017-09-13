#include "trialController.h"
#include "bubblesort.h"
#include "dataGenerator.h"

trialController::trialController()
{
	//ctor
}
trialController::~trialController()
{
	//dtor
}
		
void trialController::runTrial(int numItems, int indexValue)
{
	//creates a reference to a newly generated vector 
	std::vector<int> *vectorPtr = dGen.genVector(numItems);
	std::vector<int> &newVector = *vectorPtr;
	
	//records time for sorting a randomly generated vector
	baseTrials[indexValue] = sorter.doBubblesort(newVector, numItems);
	
	//sorts the previously sorted vector again, where it is in optimal conditions
	bestTimes[indexValue] = sorter.doBubblesort(newVector, numItems);
	
	//reverses the sorted vector, times bubblesort in worst conditions
	std::reverse(newVector.begin(), newVector.end());
	worstTimes[indexValue] = sorter.doBubblesort(newVector, numItems);
}

//precondition: one iteration of runTrial must have been executed prior to running generateAves()
void trialController::generateAves()
{
	float normalAve = 0.0, bestAve = 0.0, worstAve = 0.0;
	
	for (int i = 0; i < 5; i++)
	{
		normalAve += baseTrials[i];
		bestAve += bestTimes[i];
		worstAve += worstTimes[i];
	}
	
	averageTime = normalAve / 5;
	aveBestTime = bestAve / 5;
	aveWorstTime = worstAve / 5;
}

void trialController::resetValues()
{
	averageTime = 0;
	aveBestTime = 0;
	aveWorstTime = 0;
	
	for (int i = 0; i < 5; i++)
	{
		baseTrials[i] = 0;
		bestTimes[i] = 0;
		worstTimes[i] = 0;
	}
}
