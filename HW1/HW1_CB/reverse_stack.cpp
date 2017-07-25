#include "reverse_stack.h"

RevStack::RevStack()
{
    mpTop = nullptr;
}

RevStack::RevStack(RevStack &copy) //copy constructor
{
    while(RevStack::mpTop != nullptr)
    {
        //not finished
    }
}
RevStack::~RevStack() //deconstructor
{
    destoryStack();
}
//RevStack & operator= (const RevStack &rhs); //overloaded assign. operator ; deep copy

//getters
StackNode * RevStack::getTopPtr () const //returns ptr of mpTop
{
    return mpTop;
}
//setters
void RevStack::setTopPtr(StackNode *newTop) //sets new top of stack ptr
{
    this->mpTop = newTop;
}

bool RevStack::insertAtTop(const int newData) //inserts data to top of stack
{

}

//memberFunctions
void RevStack::Push(int item) //pushes an item onto the top of the stack
{
    StackNode *newTop;
    newTop = makeNode(item);
    newTop->setNextPtr(mpTop);
    //mpTop = newTop;
}
int RevStack::Pop() //pops an item off the top of the stack and returns it
{
    int returnDat = mpTop->getData();
    StackNode *tempTop = mpTop;
    mpTop = mpTop->getNextPtr();
    tempTop->~StackNode();

    return returnDat;
}
bool RevStack::IsEmpty() const //returns true if the stack is empty
{
    if(mpTop == nullptr) return true;
        else return false;
}
void RevStack::Reverse() //reverses the order of items on the stack by reversing the singly linked list
{
    RevStack *newStack;
    while(mpTop!=nullptr)
    {
        newStack->Push(Pop());
    }
}
void RevStack::Display() const //std::ostream & writer
{
    while(mpTop != nullptr) //iterate through stack and write data, then add a space
    {
        cout << mpTop->getData() << " ";
    }
        cout << endl; //once nullptr is hit, add new line

}

//private
StackNode * RevStack::makeNode (const int newData)
{
    StackNode *newNode = new StackNode(newData);

return newNode;
}
void RevStack::destoryStack()
{
    while(this != nullptr)
    {
        this->Pop();
    }

}
