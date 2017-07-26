#ifndef BST_H
#define BST_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct BSTnode
{
    int data; //each node will have a variable called data
    struct BSTnode *pLeft; //self-referential part, where each node
                            //will contain a pointer to a node
    struct BSTnode *pRight;

}BSTNode;

BSTNode * makeNode (int data); //made node function, w/ data in parameters to set function right away
void insertBST (BSTnode **pTree, int newData);//insert into BST, must send root node and new data

#endif // BST_H
