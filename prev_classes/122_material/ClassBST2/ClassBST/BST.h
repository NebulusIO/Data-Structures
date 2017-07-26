#ifndef BST_H
#define BST_H

#include <iostream>
#include "BSTNode.h"

using std::cin;
using std::cout;
using std::endl;

class BST // container class
{
	public:
		BST ();
		BST (BST &copy);
		~BST ();

		BST & operator= (BST &rhs);

		void insert (Rational &newData);
		void inOrderTraversal ();
		void preOrderTraversal ();
		void postOrderTraversal ();

	private:
		BSTNode *mpRoot;
		void destroyTree (BSTNode *pTree);
		void inOrderTraversal (BSTNode *pTree);
		void preOrderTraversal (BSTNode *pTree);
		void postOrderTraversal (BSTNode *pTree);
		void insert (BSTNode **pTree, Rational &newData);
		BSTNode * makeNode (Rational &newData);
};

#endif