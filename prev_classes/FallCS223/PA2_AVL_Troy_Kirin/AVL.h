/**********************************************************
 * AVL Tree Implementation file
 *
 *  ** riffed and modified heavily by Aaron Crandall - 2016
 *  ** All implementation in header because of templating
 *
 **********************************************************/

#ifndef AVLTREE_H_
#define AVLTREE_H_

#include <queue>
#include <iostream>

using namespace std;

template<class T>
class AVLNode {
public:
    // Default blank AVLNode constructor
    AVLNode() {
        left = right = nullptr;
        height = 0;
    }

    // Constructor with provided element (data) and children
    AVLNode(const T& el, AVLNode *l = nullptr, AVLNode *r = nullptr) {
        key = el;
        left = l;
        right = r;
        height = 0;
    }

    T key;                  // Key to compare/insert on of type <T>
    AVLNode *left, *right;  // Children of this node
    int height;             // Height of this node in the tree
};

/*
 * Main AVLTree class that stores AVLNode objects
 *  -- REQUIRES: implementation of rotation functions
 *  -- REQUIRES: implementation of node heights
 *  -- REQUIRES: implementation of contains function
 *  -- REQUIRES: implementation of remove function
 */
template<class T>
class AVLTree {
  public:
    AVLTree() { root = nullptr; }

    void rightRotation() {rightRotation(root); }


    int height() const {height(root) ;} //return height of node; const function doesn't allow function to change anything / read only
    void balance() {balance(root);} //needs fix

    void insert(const T& key) { insert(root, key); } //needs fixing
    void printTree() { printTree(root); } //works

    bool contains( const T& key ){ return(contains(root, key)); } //works
    void remove( const T& key ){ remove(root, key); } //still need to write

  private:
    AVLNode<T>* root;
    static const int ALLOWED_IMBALANCE = 1;

    /*
     *Return the height of node t or -1 if nullptr
     */
    int height(AVLNode<T> *node) const {
        return node == nullptr ? -1 : node->height;
    }

    /*
     *Assume node is balanced or within one of being balanced
     */
    void balance(AVLNode<T>* &node) {
        if(node == nullptr) //if tree is empty, there needs no balancing
            return;

        if(height(node->left) - height(node->right) > ALLOWED_IMBALANCE)
            if(height(node->left->left) >= height(node->left->right))
                rotateWithLeftChild(node);
            else
                doubleWithLeftChild(node);

        else
        if (height(node->right) - height(node->left) > ALLOWED_IMBALANCE)
            if(height(node->right->right) >= height(node->right->left))
                rotateWithRightChild(node);
            else
                doubleWithRightChild(node);

        node->height = max(height(node->left), height(node->right)) + 1;
    }

/********************************************************************/
/*****************************ROTATIONS******************************/
/********************************************************************/
    void rightRotation(AVLNode<T>* &node) {
      AVLNode<T>* left = node->left;

      node->left = left->right;
      left->right = node;
      node = left;
    }

    void rotateWithLeftChild(AVLNode<T>* &node) { /**what I call a right rotation*/
        //rotate ptrs
        AVLNode<T> *left = node->left;
        node->left = left->right;
        left->right = node;
        //update height
        node->height = max( height(node->left), height(node->right))+1;
        left->height = max( height(left->left), node->height ) +1;
        //set newRoot
        node = left;
    }

    void rotateWithRightChild(AVLNode<T>* &node) { /**left rotation*/
        //rotate ptrs
        AVLNode<T> *right = node->right;
        node->right = right -> left;
        right->left = node;
        //update height
        node->height = max( height(node->left), height(node->right))+1;
        right->height = max( height(right->right), node->height ) +1;
        //set newRoot
        node = right;
    }

    void doubleWithRightChild(AVLNode<T>* &node) {
        rotateWithLeftChild(node->right);
        rotateWithRightChild(node);
    }

    void doubleWithLeftChild(AVLNode<T>* &node) {
        rotateWithRightChild(node->left);
        rotateWithLeftChild(node);
    }

/**********************************************************************************/
    /*
     *  Insert function needs updating!
     *  This function needs to update heights as it returns from recursive insert.
     *  If the heights of a node are more than 2 different, rotate to fix
     *  After fixing, repair the heights of all nodes in the rotated tree
     */

     /*
     *Internal method to insert to subtree
     * key is the data to insert
     * node is the root node of subtree
     * set new root of subtree
     */
    void insert(AVLNode<T>* &node, const T& key) {
      if(node == nullptr) //root is empty, so insert as root
      {
        node = new AVLNode<T>(key,nullptr,nullptr); //allocate memory for node, size of "key"
      }

      else if(node->key < key) //insert node is greater than comparing node
      {

        insert(node->right, key); //insert node to the right ptr
      }

      else //insert node is less than comparing node
      {
        //node->left = new AVLNode<T>(key,nullptr,nullptr);
        insert(node->left, key);
      }


        balance(node);

    }

    /*
     *Searches tree if a given node exists
     *returns bool (T/F)
     *given node we're looking for is 'key'
     */
    bool contains(AVLNode<T>* root, const T& key) {
      //cout << "CONTAINS STILL UNIMPLEMENTED" << endl;
      if (root == nullptr) {
        return false;
        }

      if(root->key == key) { //node looking for is the root
        return true;
        }
      else if (root->key > key) {
        contains(root->left, key); //set newroot to left child
        }
      else if (root->key < key) {
        contains(root->right, key); //set newroot to right child
        }
      else {
        return false;
        }
    }

    // MUST IMPLEMENT REMOVE
    void remove( AVLNode<T>* root, const T& key) {
      //cout << "REMOVE STILL UNIMPLEMENTED" << endl;



    }

    // Should do a level order printout with actual depth (no alignment)
    void printTree(AVLNode<T>* node) {
      queue<AVLNode<T>*> bufQueue;
      int curr_height = node->height;
      bufQueue.push(node);
      while( !bufQueue.empty() ) {
        AVLNode<T>* curr = bufQueue.front();
        if( curr->left  != nullptr ){ bufQueue.push(curr->left ); }
        if( curr->right != nullptr ){ bufQueue.push(curr->right); }
        if( curr->height < curr_height ){
          cout << endl;
          curr_height = curr->height;
        }
        cout << curr->key << " ";
        bufQueue.pop();
      }
      cout << endl;
    }
  // end private
};

#endif
