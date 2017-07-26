#ifndef LIST_NODE_H
#define LIST_NODE_H

#include <iostream>

using std::cin;
using std::cout;
using std::endl;

// This class defines a node, which will always be dynamically allocated
class ListNode
{
	public:
		ListNode (int newData = 0); // constructor - "constructs" a ListNode; initializes the object
		ListNode (ListNode &copy);  // copy constructor - implicitly invoked when a ListNode object is passed-by-value
		~ListNode ();               // destructor - implicitly invoked when a ListNode object leaves scope

		// we will not define an explicit overloaded assignment operator (=)

		// getters
		int getData () const;                // used to retrieve a copy of the data in the node
		ListNode * getNextPtr () const;      // used to retrieve a copy of the node's next pointer

		// setters
		void setData (const int newData);            // used to modify the data in the node
		void setNextPtr (const ListNode * pNewNext); // used to modify the node's next pointer

	private:
		int mData;
		ListNode *pNext;            // should be set to NULL in the constructor
};

#endif