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
  T data;
  Node<T> *leftChild = nullptr;
  Node<T> *rightChild = nullptr;
};


/*
 * Binary Search Tree (BST) class implementation
 */
template <class T>
class BST { //BST is a container class

    private:
    Node<T> *root;

    //**HELPER FUNCTIONS**//
    Node<T> *newNode(T newData){
      Node<T> *tempNode = new Node<T>;
      tempNode->data = newData;
      tempNode->leftChild = nullptr;
      tempNode->rightChild = nullptr;

      return tempNode;
    }

    //recursively traverses to the appropriate
     void addHelper(Node<T> *root, T newData){
       if(!root)
        setRoot(newNode(newData));

       else if(root->data > newData){
        if(!root->leftChild)
          root->leftChild = newNode(newData);
        else
          addHelper(root->leftChild, newData);
        }
        else{
        if(!root->rightChild)
          root->rightChild = newNode(newData);
        else
          addHelper(root->rightChild, newData);
        }

    }

    void printPreOrderHelper(Node<T> *root){
      cout << "Running printPreOrderHelper." << endl;
      if(root)
        cout << root->data << " ";
      printPreOrderHelper(root->leftChild);
      printPreOrderHelper(root->rightChild);
    }

    int heightHelper(Node<T> *root){
      if(!root)
        return( -1 );
      else{
          int leftDepth = heightHelper(root->leftChild);
          int rightDepth = heightHelper(root->rightChild);

          if(leftDepth > rightDepth)
            return leftDepth++;
          else
            return rightDepth++;
      }
    }

    int nodesCountHelper(Node<T> *root){
      if(!root)
        return 0;
      return 1 + nodesCountHelper(root->leftChild) + nodesCountHelper(root->rightChild);
    }
    //******************************//

    public:
      //constructor
    BST(){
      root = nullptr;
    }
      //Destructor
    ~BST(){
      delete root;
    }
      //copy constructor
    BST(BST &other){
      this->root = other.root;
    }

      //setter
    void setRoot(Node<T>* newRoot){
      this->root = newRoot;
    }
      //getter
    Node<T> *getRoot(){
      return this->root;
    }

    void add(T val) {
			cout << " [x] BST::Running BST add." << endl;
      addHelper(root, val);
    }

    void print() {
			this->printPreOrder();
    }

    void printPreOrder() {
      cout << " [x] BST::printPreOrder currently running." << endl;
    //recursive solution
      printPreOrderHelper(getRoot());
    }

    int nodesCount() {
      return nodesCountHelper(root);
    }

    int height() {
      cout << " [!] BST::height currently unimplemented." << endl;
      return heightHelper(getRoot());
    }


};

#endif
