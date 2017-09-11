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
			cout << " [!] BST::add currently unimplemented." << endl;
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
