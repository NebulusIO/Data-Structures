#include "dataGenerator.h"

dataGenerator::dataGenerator()
{
	//ctor
}
dataGenerator::~dataGenerator()
{
	//dtor
}

//generate vector length N
std::vector<int>* dataGenerator::genVector(int N)
{
	std::vector<int> *newVector = new std::vector<int>(N);

	for(int i = 0; i < N; i++)
	{
		int randomVal = rand() % N+1;
		newVector->push_back(randomVal);
		//generates numbers ranging from 1-N, places into vector
	}
	return newVector;
}
