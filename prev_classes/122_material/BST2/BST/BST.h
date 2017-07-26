#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BSTnode
{
	int data;
	struct BSTnode *pLeft;
	struct BSTnode *pRight;
} BSTNode;

BSTNode * makeNode (int newData);	
void insertBST (BSTNode **pTree, int newData);

#endif