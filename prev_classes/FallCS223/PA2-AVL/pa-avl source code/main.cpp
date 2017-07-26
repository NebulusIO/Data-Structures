/*
 *  AVL Tree main function and test code
 *
 *  Aaron Crandall, 2016
 *
 */
#include <iostream>
#include <fstream>
#include <vector>
#include <stdlib.h>  // rand
#include <time.h>    // time for srand
#include "AVL.h"

int main(int argc, char* argv[]) {
  AVLTree<int> myTree;

  cout << "Sample series of inserts. Will do all 4 cases of rotates." << endl;
  myTree.insert(20);
  myTree.insert(10);
  myTree.insert(5);
  myTree.insert(30);
  myTree.insert(40);
  myTree.insert(15);
  myTree.insert(18);
  myTree.insert(13);
  myTree.insert(4);
  myTree.insert(19);
  myTree.printTree();

  if( myTree.contains(15) ){
    cout << "Tree contains 15" << endl;
  }else{
    cout << "Tree does not contain 15" << endl;
  }

  myTree.remove(15);
  if( myTree.contains(15) ){
    cout << "Tree contains 15" << endl;
  }else{
    cout << "Tree does not contain 15" << endl;
  }


  /* BIGGER test of your AVL tree! */
  vector<int> incVals;
  AVLTree<int> bigTree;
  srand (time(NULL));
  for( int i = 0; i < 300; i++ ) {
    int newVal = rand() % 900;        // Generate new integer to insert into tree
    bool skip = false;
    for( int j = 0; j < incVals.size(); j++ ){ // Very dumb search!
      if( incVals[j] == newVal ){
        skip = true;
        j = incVals.size();
      }
    }
    if( !skip ){
      bigTree.insert(newVal);
      incVals.push_back(newVal);
    }

    if( i % 3 == 0 ){   // Delete a random element every 3 inserts
      int remIndex = rand() % incVals.size();
      bigTree.remove( incVals[remIndex] );
      incVals.erase(incVals.begin() + remIndex);
    }

  }
  bigTree.printTree();
  

  return(0);
}
