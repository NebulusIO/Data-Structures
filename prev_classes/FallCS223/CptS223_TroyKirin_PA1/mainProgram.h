#ifndef MAINPROGRAM_H
#define MAINPROGRAM_H

#include "fileWriter.h"
#include "trialController.h"

class mainProgram
{
	public:
		mainProgram();
		virtual ~mainProgram();
	
		void runProgram();
	
	private:
		int nValues[8] = {10, 50, 100, 500, 1000, 5000, 10000, 50000};
		fileWriter scribe;
		trialController timeKeeper;
};

#endif
