#include "BSTNode.h"

BSTNode::BSTNode (Rational &newData)
{
	mData = newData;
	mpLeft = NULL;
	mpRight = NULL;
}

BSTNode::BSTNode (BSTNode &copy)
{
	mData = copy.mData; // applying overloaded assignment operator for Rational
	mpLeft = copy.mpLeft;
	mpRight = copy.mpRight;
}

BSTNode::~BSTNode ()
{
	cout << "Inside BSTNode's destructor" << endl;
}

// getters
Rational BSTNode::getData () 
{
	return mData;
}

BSTNode * BSTNode::getLeftPtr () 
{
	return mpLeft;
}
		
BSTNode * BSTNode::getRightPtr () 
{
	return mpRight;
}

// setters
void BSTNode::setData (Rational &newData)
{
	mData = newData;
}

void BSTNode::setLeftPtr (BSTNode *newLeftPtr)
{
	mpLeft = newLeftPtr;
}
		
void BSTNode::setRightPtr (BSTNode *newRightPtr)
{
	mpRight = newRightPtr;
}