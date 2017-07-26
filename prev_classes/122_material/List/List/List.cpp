#include "List.h"

List::List ()                    // default constructor; will always set mpHead to NULL
{
	mpHead = nullptr;
}

List::List (List &copyList)      // copy constructor - implicitly invoked when a List object is passed-by-value
{
	while (mpHead != nullptr)
	{
		mpHead->getData = copyList.insertAtFront;
		mpHead->setNextPtr = mpHead->getNextPtr;
	}
}

List::~List ()                   // destructor - implicitly invoked when a List object leaves scope
{
	destroyList ();
}

// This function must allocate new memory for each of the nodes in rhs to construct "this" object
List & List::operator= (const List &rhs) // overloaded assignment operator - must perform a deep copy
{
	// you must use a loop, which visits each of the nodes in List rhs, and assign the data to the new nodes
	// How to use new operator? ListNode *pMem = new ListNode; new is similar to the results of using malloc ()
}

// getter
ListNode * List::getHeadPtr () const     // returns a copy of the address stored in mpHead
{
	return mpHead;
}

// setter
void List::setHeadPtr (const ListNode *pNewHead) // modifies mpHead
{
	this->mpHead = pNewHead;
}
		
bool List::insertAtFront (const int newData)     // inserts newData at the beginning or front of the list
{
}

// insert newData in ascending order
bool List::insertInOrder (const int newData)     // inserts newData in ascending order
{
}

bool List::insertAtEnd (const int newData)       // inserts newData at the end of the list
{
}

// returns true if the list is empty; false otherwise
bool List::isEmpty ()                            // determines if the list is empty  
{
}

// precondition: list must not be empty
int List::deleteAtFront ()                       // deletes the node at the front of the list
{
}

// precondition: list must not be empty
bool List::deleteNode (const int searchValue)    // deletes the node with data == searchValue
{
}

// precondition: list must not be empty
int List::deleteAtEnd ()                         // deletes the node at the end of the list
{
}

void List::printList ()                          // visits each node, print the node's data
{
}

// allocates memory for a Listnode; initializes the memory with newData
ListNode * List::makeNode (const int newData)    // will only call within insert functions
{
	ListNode *pMem = new ListNode;

	pMem->setData(newData);
}
		
void List::destroyList ()                        // deletes each node to free memory; will call in the destructor
{
	ListNode *pTemp;

	while (mpHead != nullptr)
	{
		pTemp = mpHead;
		mpHead = mpHead->getNextPtr;
		pTemp->~ListNode();
	}
}