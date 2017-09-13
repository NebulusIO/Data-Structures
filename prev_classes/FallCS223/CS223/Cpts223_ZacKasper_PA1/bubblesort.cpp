#include "bubblesort.h"

bubblesort::bubblesort()
{
    //ctor
}

bubblesort::~bubblesort()
{
    //dtor
}

float bubblesort::doBubblesort(std::vector<int> &vect, int N)
{
    std::chrono::time_point<std::chrono::system_clock> start, stop;
    start = std::chrono::system_clock::now();

    //timer has begun, bubblesort now begins
    for(int j = 0; j < (N - 1); j++)
    {
        for (int i = 0; i < N - j - 1; i++)
        {
            if (vect[i] > vect[i+1])
            {
                vect[i] += vect[i+1];
                vect[i+1] = vect[i] - vect[i+1];
                vect[i] -= vect[i+1];
            }
        }
    }
    //bubblesort has ended, timer will stop here
    stop = std::chrono::system_clock::now();

    std::chrono::duration<float> elapsed_time = stop - start;
    //elasped time for the bubblesort to execute

    return elapsed_time.count();
}
