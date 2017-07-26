#ifndef DATAGENERATOR_H
#define DATAGENERATOR_H

#include <vector>
#include <cstdlib>
#include <ctime>

class dataGenerator
{
	public:
		dataGenerator();
		virtual ~dataGenerator();

		//generate vector length N
		std::vector<int> *genVector(int N);	
		
};

#endif
