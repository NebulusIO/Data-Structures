#include "ListNode.h"

ListNode::ListNode (int newData)
{
	mData = newData;
	pNext = nullptr;
}

ListNode::ListNode (ListNode &copy)
{
	this->setData = copy.getData;
	this->setNextPtr = copy.getNextPtr;
}

ListNode::~ListNode ()
{
	cout << mData << endl;
	delete (this);
}

int ListNode::getData () const // the const indicates "constant" function; can't modify the object's data members with this function
{
	return this->mData;
}

ListNode * ListNode::getNextPtr () const // the const indicates "constant" function; can't modify the object's data members with this function
{
	return this->pNext;
}

void ListNode::setData (const int newData) // the const in this context ensures newData can't be modified
{
	this->mData = newData;
}

void ListNode::setNextPtr (const ListNode *pNewNext) // the const in this context ensures pNewNext can't be modified
{
	const ListNode *next = pNewNext;

}