#include "BST.h"

BSTnode * makeNode(int newData)
{
    BSTnode *pMem = NULL;

    pMem = (BSTnode*) malloc(sizeof(BSTNode));

    if(pMem != NULL)
    {
        pMem -> data = newData;
        pMem -> pLeft = nullptr;
        pMem -> pRight = nullptr;
    }

    return pMem;
}

void insertBST(BSTnode **pTree, int newData)
{
    BSTnode *pMem = nullptr;

    //pMem = makeNode(newData); //this could lead to memory leaks...why??

    if(*pTree == nullptr) //empty tree
    {
        *pTree = pMem;
    }

    else if((*pTree.data) < newData)//right subtree
    {
        //recursive step
        insertBST(&(*pTree->pRight), newData);
    }

    else if((*pTree.data)>newData)//left subtree
    {
        insertBST(&(*pTree.pLeft), newData)
    }


}
