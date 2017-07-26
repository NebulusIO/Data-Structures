#include "BST.h"

BST::BST ()
{
	mpRoot = NULL;
}

BST::BST (BST &copy)
{
}

BST::~BST ()
{
	destroyTree (mpRoot);
}

BST & BST::operator= (BST &rhs)
{
	// assign rhs to this' data members

	return *this;
}

// ---------------- public member functions below ----------------

void BST::insert (Rational &newData)
{
	insert (&mpRoot, newData);
}
		
void BST::inOrderTraversal ()
{
	inOrderTraversal (mpRoot);
}

void BST::preOrderTraversal ()
{
	preOrderTraversal (mpRoot);
}


void BST::postOrderTraversal ()
{
	postOrderTraversal (mpRoot);
}

// ---------------- private member functions below ----------------

void BST::destroyTree (BSTNode *pTree)
{
	//recursively destroy entire tree

	if (pTree != nullptr)
	{
		destroyTree(pTree->mpLeft); // go far left as possible
		destroyTree(pTree->mpRight); // go far right as possible
		delete pTree;
		cout << "Deleting node with Rational number: " << pTree->getData() << endl; // Note: Rational's overloaded << is called here!

	}

}

void BST::inOrderTraversal (BSTNode *pTree)
{
}

void BST::preOrderTraversal (BSTNode *pTree)
{
}

void BST::postOrderTraversal (BSTNode *pTree)
{
}

void BST::insert (BSTNode **pTree, Rational &newData)
{
	if ((*pTree) == NULL) //base case
	{
		BSTNode *pMem = makeNode(newData);
		*pTree = pMem;
	}
	else if (newData > (*pTree)->mData)//->getData()
	{
		insert(&((*pTree)->mpRight), newData);
	}
	else if (newData < (*pTree)->mData)
	{
		insert(&((*pTree)->mpLeft), newData);
	}

	else
	{
		cout << "Dup" << endl;
	}
}

BSTNode * BST::makeNode (Rational &newData)
{
	BSTNode *pMem = NULL;

	pMem = new BSTNode(newData); //invoking constructor


	return pMem;
}