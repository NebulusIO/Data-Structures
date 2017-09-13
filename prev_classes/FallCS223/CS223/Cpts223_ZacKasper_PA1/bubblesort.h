#ifndef BUBBLESORT_H
#define BUBBLESORT_H

#include <chrono>
#include <ctime>
#include <vector>

class bubblesort
{
    public:
        bubblesort();
        virtual ~bubblesort();

        float doBubblesort(std::vector<int>& vect, int N);
};

#endif // BUBBLESORT_H
