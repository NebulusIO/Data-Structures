#ifndef BST_NODE_H
#define BST_NODE_H

#include <iostream>
#include "Rational.h"


using std::cin;
using std::cout;
using std::endl;

class BST; // forward declaration

class BSTNode
{
	friend class BST;

	public:
		BSTNode (Rational &newData);
		BSTNode (BSTNode &copy);
		~BSTNode ();

		// getter
		Rational getData ();
		BSTNode * getLeftPtr ();
		BSTNode * getRightPtr ();

		// setters
		void setData (Rational &newData);
		void setLeftPtr (BSTNode *newLeftPtr);
		void setRightPtr (BSTNode *newRightPtr);


	private:
		Rational mData;
		BSTNode *mpLeft;
		BSTNode *mpRight;
};

#endif