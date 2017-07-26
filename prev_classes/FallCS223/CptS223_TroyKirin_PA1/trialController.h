#ifndef TRIALCONTROLLER_H
#define TRIALCONTROLLER_H

#include <algorithm>
#include "bubblesort.h"
#include "dataGenerator.h"

class trialController
{
	public:
		trialController();
		virtual ~trialController();
		
		void runTrial(int numItems, int indexVal);
		void generateAves();
		void resetValues();
	
	//private:
		float baseTrials[5];
		float averageTime;
		
		float bestTimes[5];
		float aveBestTime;
		
		float worstTimes[5];
		float aveWorstTime;
		
		bubblesort sorter;
		dataGenerator dGen;
};

#endif
