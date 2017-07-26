#pragma once
/*
 * Binary Search Tree implementation
 *  - heavily lifted from https://gist.github.com/mgechev/5911348
 *
 * Simple integer keys and basic operations BST
 *
 * Aaron Crandall - 2016 - Added / updated:
 *  * Inorder, Preorder, Postorder printouts
 *  * Stubbed in level order printout
 *
 */
#include <iostream>
#include <queue>

using namespace std;

/*
 *  Node datastructure for single tree node
 */
template <class T>
struct Node {
    T value;
    Node *left;
    Node *right;

    Node(T val) {
        this->value = val;
    }

    Node(T val, Node<T> left, Node<T> right) {
        this->value = val;
        this->left = left;
        this->right = right;
    }
};

/*
 * Binary Search Tree (BST) class implementation
 */
template <class T>
class BST {

    private:
    Node<T> *root;

    void addHelper(Node<T> *root, T val) {
        if (root->value > val) { //val is less than root
            if (!root->left) { //root's left child is empty
                root->left = new Node<T>(val); //create new node w/ val & set to root left
            } else {
                addHelper(root->left, val); //recursive step; send root left child and same val
            }
        } else {
            if (!root->right) { //root's right child is empty
                root->right = new Node<T>(val); //create new node w/ val & set to root's right child
            } else {
                addHelper(root->right, val); //recursive step; send root right child and same val
            }
        }
    }

    void printInOrderHelper(Node<T> *root) { //inorder print;
        if (!root) return; //if root is empty, then leave function
        printInOrderHelper(root->left); //root not empty, send left child in
        cout<<root->value<<' '; //print current node val
        printInOrderHelper(root->right); //
    }

    void printPostOrderHelper(Node<T> *root) {
        if (!root) return; //stop if no more nodes / list is empty
        printPostOrderHelper(root->left); //
        printPostOrderHelper(root->right);
        cout<<root->value<<' ';
    }

    void printPreOrderHelper(Node<T> *root) {
        if (!root) return;
        cout<<root->value<<' ';
        printPreOrderHelper(root->left);
        printPreOrderHelper(root->right);
    }

    /*
        Level order prints out by "height" starting w/ root
        ex. height d will be processed before d+1
    */

    void printLevelOrderHelper(Node<T> *root) {
    if (!root) return; //check if tree is empty; there exists at least 1 node
    queue<Node<T>*> Q; //create a queue of Node pointers named Q
    Q.push(root); //push the root node into the queue for processing

    /*generally what will happen is.
    * The front node will be processed by first printing it's data(value), checking if there is a left child and a right child...in that order
    * if there is a left child it will be pushed onto queue(Q) and if there is a right child then it will be pushed onto Q as well
    * once front node is printed, checked for a left and right child it will be poped off the queue.
    * since I'm using a while loop this will keep going with the next node in queue until all nodes have been added to the queue and popped off
    * will end when queue(Q) is empty
    */

    while(!Q.empty()) {
        Node<T>* current = Q.front();
        cout << current->value << " ";
        if(current->left != nullptr)
            Q.push(current->left);
        if(current->right != nullptr)
            Q.push(current->right);
        Q.pop();
        }

    }

    int nodesCountHelper(Node<T> *root) {
        if (!root) return 0;
        else return 1 + nodesCountHelper(root->left) + nodesCountHelper(root->right);
    }

    int heightHelper(Node<T> *root) {
        if (!root) return 0;
        else return 1 + max(heightHelper(root->left), heightHelper(root->right));
    }

    void printMaxPathHelper(Node<T> *root) {
        if (!root) return;
        cout<<root->value<<' ';
        if (heightHelper(root->left) > heightHelper(root->right)) {
            printMaxPathHelper(root->left);
        } else {
            printMaxPathHelper(root->right);
        }
    }

    bool deleteValueHelper(Node<T>* parent, Node<T>* current, T value) {
        if (!current) return false;
        if (current->value == value) {
            if (current->left == NULL || current->right == NULL) {
                Node<T>* temp = current->left;
                if (current->right) temp = current->right;
                if (parent) {
                    if (parent->left == current) {
                        parent->left = temp;
                    } else {
                        parent->right = temp;
                    }
                } else {
                    this->root = temp;
                }
            } else {
                Node<T>* validSubs = current->right;
                while (validSubs->left) {
                    validSubs = validSubs->left;
                }
                T temp = current->value;
                current->value = validSubs->value;
                validSubs->value = temp;
                return deleteValueHelper(current, current->right, temp);
            }
            delete current;
            return true;
        }
        return deleteValueHelper(current, current->left, value) ||
               deleteValueHelper(current, current->right, value);
    }

    public:
    void add(T val) {
        if (root) { //if root is not empty
            this->addHelper(root, val);
        } else { //root is empty so set to new node w/ val
            root = new Node<T>(val);
        }
    }

    void print() {
        printInOrderHelper(this->root);
    }

    void printInOrder() {
        printInOrderHelper(this->root);
    }

    void printPostOrder() {
        printPostOrderHelper(this->root);
    }

    void printPreOrder() {
        printPreOrderHelper(this->root);
    }

    void printLevelOrder() {
        printLevelOrderHelper(this->root);
    }

    int nodesCount() {
        return nodesCountHelper(root);
    }

    int height() {
        return heightHelper(this->root);
    }

    void printMaxPath() {
        printMaxPathHelper(this->root);
    }

    bool deleteValue(T value) {
        return this->deleteValueHelper(NULL, this->root, value);
    }
};

/*
int main()
{
    BST<int> *bst = new BST<int>();
    bst->add(4);
    bst->add(2);
    bst->add(1);
    bst->add(3);
    bst->add(6);
    bst->add(5);
    bst->add(7);
    bst->add(9);
    bst->add(8);


    cout << "Inorder: \t";
    bst->printInOrder();
    cout << endl;

    cout << "Postorder: \t";
    bst->printPostOrder();
    cout << endl;

    cout << "Preorder: \t";
    bst->printPreOrder();
    cout << endl;

    cout << "Levelorder: \t";
    bst->printLevelOrder();
    cout << endl;
    cout << "Should produce:\t4 2 6 1 3 5 7 9 8" << endl;


    cout<<endl;
    cout<<"Nodes count: "<<bst->nodesCount();
    cout<<endl;
    cout<<"Height: "<<bst->height();
    cout<<endl;
    cout<<"Max path: ";
    bst->printMaxPath();
    cout<<endl;
    return 0;
}
*/
