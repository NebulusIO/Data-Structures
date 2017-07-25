#ifndef STACKNODE_H
#define STACKNODE_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

class StackNode
{
    public:
        StackNode (int newData = 0); //constructor, initialize newData to 0;
        StackNode (StackNode &copy); //copy constructor, pass by value
        ~StackNode (); //deconstructor

    //getters
        int getData() const; //returns data
        StackNode* getNextPtr() const;

    //setters
        void setData(const int newData); //modify StackNode's data to newData
        void setNextPtr(StackNode* pNewNext); //modify StackNode's next ptr

    private:
    //memberVariables
        int mData;
        StackNode *pNext;    //sets to NULL in constructor
};

#endif
