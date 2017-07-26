#ifndef LIST_H
#define LIST_H

#include <iostream>
#include "ListNode.h"

using std::cin;
using std::cout;
using std::endl;

// This class defines a container for a list; it's a singly linked list
class List
{
	public:
		List ();                    // default constructor; will always set mpHead to NULL
		List (List &copyList);      // copy constructor - implicitly invoked when a List object is passed-by-value
		~List ();                   // destructor - implicitly invoked when a List object leaves scope

		List & operator= (const List &rhs); // overloaded assignment operator - must perform a deep copy

		// getter
		ListNode * getHeadPtr () const;     // returns a copy of the address stored in mpHead

		// setter
		void setHeadPtr (const ListNode *pNewHead); // modifies mpHead
		
		bool insertAtFront (const int newData);     // inserts newData at the beginning or front of the list
		bool insertInOrder (const int newData);     // inserts newData in ascending order
		bool insertAtEnd (const int newData);       // inserts newData at the end of the list

		bool isEmpty ();                            // determines if the list is empty  

		int deleteAtFront ();                       // deletes the node at the front of the list
		bool deleteNode (const int searchValue);    // deletes the node with data == searchValue
		int deleteAtEnd ();                         // deletes the node at the end of the list

		void printList ();                          // visits each node, print the node's data - we could also overload the stream insertion << operator to print the list

	private:
		ListNode *mpHead;

		// yes, we can make member functions private as well
		ListNode * makeNode (const int newData);    // will only call within insert functions
		void destroyList ();                        // deletes each node to free memory; will call in the destructor
};

#endif