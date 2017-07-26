#include <iostream>
#include "bst-levelorder.cpp"

using namespace std;

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
