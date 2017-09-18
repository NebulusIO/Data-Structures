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

    Node<T> *newNode(T newData){
      Node<T> *tempNode = new Node<T>;
      tempNode->data = newData;
      tempNode->leftChild = nullptr;
      tempNode->rightChild = nullptr;

      return tempNode;
    }

    //**helper function**//
    //recursively traverses to the appropriate
     void insert(Node<T> *root, T newData){
      if(root == nullptr) {
        root = newNode(newData);
        cout << "Just inserted: " << root->data << " at root." << endl;
      }

      else if(newData < root->data){
        if(root->leftChild != nullptr)
          insert(root->leftChild, newData);
        else
          root->leftChild = newNode(newData);
          cout << "Just inserted: " << root->leftChild->data << " at leaf." << endl;
      }

      else if(root->data < newData){
        if(root->rightChild != nullptr)
          insert(root->rightChild, newData);
        else
          root->rightChild = newNode(newData);
          cout << "Just inserted: " << root->rightChild->data << " at leaf." << endl;
      }

      else {cout << "ERROR: Something went wrong inserting!" << endl;}
    }

    public:
    void add(T val) {
			cout << " [x] BST::Running BST add." << endl;
      insert(this->root, val);


      /*
      //if root is empty; add val to root node
      if(tempRoot == nullptr){
        tempRoot = newNode(val);
      }

      //if val is <= than root; make a new Node to the left of root; make sure left child is empty
      else if(val <= tempRoot->data){
        if(tempRoot->leftChild == nullptr)
          tempRoot->leftChild = newNode(val);
        else{
          while(tempRoot->leftChild != nullptr){
            tempRoot = move(tempRoot->leftChild);
          }
          tempRoot->leftChild = newNode(val);
        }

      }
      //else; val is > than root; make a new Node to right of root; make sure right child is also empty
      else if (val > tempRoot->data){
        if(tempRoot->rightChild == nullptr)
          tempRoot->rightChild = newNode(val);
        else{
          while(tempRoot->leftChild != nullptr){
            tempRoot = move(tempRoot->leftChild);
          }
          tempRoot->leftChild = newNode(val);
        }

      }

      else{
        cout << "ERROR: something went wrong with add(T val) function." << endl;
      }
      */

    }

    void print() {
			this->printPreOrder();
    }

    void printPreOrder() {
      cout << " [x] BST::printPreOrder currently running." << endl;
      Node<T> *tempRoot = this->root;

    //recursive solution
      printPreOrderHelper(tempRoot);

    //iterative solution
      /*
      Node<T> *tempNode = this->root;
      queue<Node<T> *> nodeStack;
      nodeStack.push(tempNode);

      while(nodeStack.empty() == false){
        tempNode = nodeStack.front();
        cout << tempNode->data << " ";
        nodeStack.pop();

        if(tempNode->rightChild)
          nodeStack.push(tempNode->rightChild);
        if(tempNode->leftChild)
          nodeStack.push(tempNode->leftChild);
      }
      */
    }

    void printPreOrderHelper(Node<T> *root){
      cout << "Running printPreOrderHelper." << endl;
      if(root != nullptr)
        cout << root->data << ' ';
      printPreOrderHelper(root->leftChild);
      printPreOrderHelper(root->rightChild);
    }

    int nodesCount() {
    }

    int height() {
      cout << " [!] BST::height currently unimplemented." << endl;

      return( -1 );
    }
};

#endif
