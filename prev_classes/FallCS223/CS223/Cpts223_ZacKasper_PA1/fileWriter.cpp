#include "fileWriter.h"

fileWriter::fileWriter()
{
	//ctor
}
fileWriter::~fileWriter()
{
	//dtor
}
		
//opens file, writes what each column represents 
int fileWriter::fileOpener()
{
	outfile.open("BSStats.csv");
	if (outfile.is_open())
	{
		outfile << "N Size,Optimal Time,Worst Case Time,Average Sort Time,Run #1,Run #2,Run #3,Run #4,Run #5\n";
		return 1;
	}
	return 0;
}
void fileWriter::fileCloser()
{
	outfile.close();
}

//precondition: outfile must be open
void fileWriter::entryWriter(float trialTimes[5], float bestTime, float worstTime, float aveTime, int numItems)
{
	outfile << numItems << ";" << bestTime << ";" << worstTime << ";" << aveTime << ";";
	for (int i = 0; i < 5; i++)
	{
		outfile << trialTimes[i] << ";";
	}
	outfile << "\n";
}
