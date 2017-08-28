/*
Francis Troy Kirinhakone
11429784
CptS223 - Summer 2017 - EOlds
HW1
*/

#ifndef REVSTACK_H
#define REVSTACK_H
#include "StackNode.h"

using namespace std;

class RevStack
{
    public:
        RevStack();//constructor
        RevStack(RevStack &copy); //copy constructor
        ~RevStack(); //deconstructor
        RevStack & operator= (const RevStack &rhs); //overloaded assign. operator ; deep copy

        //getters
        StackNode *getTopPtr () const; //returns ptr of mpTop
        //setters
        void setTopPtr(StackNode *newTop); //sets new top of stack ptr
        bool insertAtTop(const int newData); //inserts data to top of stack

        //memberFunctions
        void Push(int item); //pushes an item onto the top of the stack
        int Pop(); //pops an item off the top of the stack and returns it
        bool IsEmpty() const; //returns true if the stack is empty
        void Reverse(); //reverses the order of items on the stack by reversing the singly linked list
        void Display() const;

        //std::ostream & writer


    private:
        StackNode *mpTop;
        StackNode *makeNode (const int newData);
        void destoryStack();

};


#endif //REVSTACK_H
