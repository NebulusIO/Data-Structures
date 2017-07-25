#include "StackNode.h"


StackNode::StackNode (int newData) //constructor, initialize newData to 0;
{
    this->mData = newData;
    this->pNext = nullptr;
}


StackNode::StackNode (StackNode &copy) //copy constructor, pass by value
{
   // this->setData() = copy.getData();
    //this->setNextPtr() = copy.getNextPtr();
}

StackNode::~StackNode () //deconstructor
{
    delete (this);
}

    //getters

int StackNode::getData() const //returns data
{
    return mData;
}
StackNode* StackNode::getNextPtr() const
{
    return this->pNext;
}

    //setters
void StackNode::setData(const int newData) //modify StackNode's data to newData
{
    mData = newData;
}


void StackNode::setNextPtr(StackNode* pNewNext) //modify StackNode's next ptr
{
    pNext = pNewNext;
}
