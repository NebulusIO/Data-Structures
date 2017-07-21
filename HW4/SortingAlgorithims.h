#ifndef SORTINGALG_H
#define SORTINGALG_H

#include <string> //stoi
#include <vector>
#include <iostream>
#include <cstdlib>

using namespace std;

struct Item {
    int index;
    int value;
    string segment;
};

class SortAlg; //insertion_sort, shell_sort, merge_sort, quicksort

class SortAlg {
    public:
        SortAlg();
        ~SortAlg();
        SortAlg(SortAlg &copy);

        void Set(string inc_val_n_loc);

        void insertion();

        void shell(int gap1, int gap2, int gap3);

        void merge_sort();

        void merge_sort(vector<Item> & arr1, vector<Item> & arr2, int left, int right);

        void merge_(vector<Item> & arr1, vector<Item> & arr2, int leftPos, int rightPos, int rightEnd);

        int partition_(std::vector<Item> & v, int left, int right);

        void quick_sort(); //driver

        void quick_sort(std::vector<Item> & v, int left, int right); //recursive function

        void printArray(){
            cout << "Set is now: " << endl;
           for(int i = 0; (unsigned)i < this->m_string.size(); i++)
            cout << this->m_string[i].value << "," << this->m_string[i].index << endl;
        }

        //accessors

        //mutators

        //vector<Item> m_string;

    private:
        std::vector<Item> m_string;

    protected:

};

#endif //SORTINGALG_H
