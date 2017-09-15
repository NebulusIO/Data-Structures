/*
 * Binary Search Tree implementation - heavily lifted from https://gist.github.com/mgechev/5911348
 *
 * Simple integer keys and basic operations
 *
 * Aaron Crandall - 2016 - Added / updated:
 *  * Inorder, Preorder, Postorder printouts
 *  * Stubbed in level order printout
 *
 */

#ifndef _BST_H
#define _BST_H

#include <iostream>
#include <queue>
using namespace std;

/*
 *  Node datastructure for single tree node
 */
template <class T>
struct Node {
  int int_val;
  Node<T> *leftChild = nullptr;
  Node<T> *rightChild = nullptr;
};


/*
 * Binary Search Tree (BST) class implementation
 */
template <class T>
class BST {

    private:
    Node<T> *root;

    public:
    void add(T val) {
			cout << " [x] BST::Running BST add." << endl;
      //if val is < than root; make a new Node to the left of root
      if(val < root->int_val){
        root->leftChild = new Node<T>;
        root->leftChild->int_val = val;
      }
      //else; val is < than root; make a new Node to right of root
      else{
        root->rightChild = new Node<T>;
        root->rightChild->int_val = val;
      }

    }

    void print() {
			this->printPreOrder();
    }

    void printPreOrder() {
      cout << " [!] BST::printPreOrder currently unimplemented." << endl;
    }

    int nodesCount() {
    }

    int height() {
      cout << " [!] BST::height currently unimplemented." << endl;
      return( -1 );
    }
};

#endif
