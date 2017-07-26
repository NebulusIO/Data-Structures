#include "TestBST.h"

void testInsertBST (void)
{
	BSTNode *pTree = NULL; // tree is empty

	insertBST (&pTree, 25);
	insertBST (&pTree, 15);

	/*if ((pTree != NULL) && (pTree -> data == 25))
	{
		printf ("Test case succeeded\n");
	}
	else
	{
		printf ("Test case failed\n");
	}*/

	if ((pTree != NULL) && (pTree -> pLeft -> data == 15))
	{
		printf ("Test case succeeded\n");
	}
	else
	{
		printf ("Test case failed\n");
	}
}