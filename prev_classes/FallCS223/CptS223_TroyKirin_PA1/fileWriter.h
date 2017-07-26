#ifndef FILEWRITER_H
#define FILEWRITER_H

#include <iostream>
#include <fstream>

class fileWriter
{
	public:
		fileWriter();
		virtual ~fileWriter();
		
		//opens file, writes what each column represents 
		int fileOpener();
		void fileCloser();
		void entryWriter(float trialTimes[5], float bestTime, float worstTime, float aveTime, int numItems);

	private:
		//.csv file 
		std::ofstream outfile;
};

#endif
