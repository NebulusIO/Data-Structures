#include "BST.h"

BSTNode * makeNode (int newData)
{
	BSTNode *pMem = NULL;

	pMem= (BSTNode *) malloc (sizeof (BSTNode));

	if(pMem != NULL)
	{
		pMem -> data = newData;
		pMem -> pLeft = NULL;
		pMem -> pRight = NULL;
	}
	return pMem;
}


// We have yet to complete insertBST ()!
void insertBST (BSTNode **pTree, int newData)
{
	BSTNode *pMem = NULL;

	//pMem = makeNode (newData); // cautious - could lead to memory leaks

	//if (pMem != NULL)
	//{
		if (*pTree == NULL) // empty tree
		{
			pMem = makeNode (newData); // memory was allocated
			*pTree = pMem;
		}
		else if ((*pTree) -> data < newData) // right subtree
		{
			// recursive step
			insertBST (&((*pTree) -> pRight), newData);

		}
		else if ((*pTree) -> data > newData)
		{
			insertBST (&((*pTree) -> pLeft), newData);
		}
	//}
}