#include "Node.h"
template<class ItemType>
Node<ItemType>::Node()
	: item(nullptr), LChild(nullptr), RChild(nullptr){} 

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem) 
	: item(anItem), LChild(nullptr), RChild(nullptr){} 

template<class ItemType>
Node<ItemType>::Node(const ItemType& anItem, Node<ItemType>* leftPtr,
	Node<ItemType>* rightPtr) 
	: item(anItem), LChild(leftPtr), RChild(rightPtr){}

template<class ItemType>
void Node<ItemType>::setItem(const ItemType& anItem)
{
	item = anItem;
}  

template<class ItemType>
ItemType Node<ItemType>::getItem() const
{
	return item;
}

template<class ItemType>
bool Node<ItemType>::isLeaf() const
{
	return ((leftChildPtr == nullptr) && (RChild == nullptr));
}

template<class ItemType>
void Node<ItemType>::setLeftChildPtr(Node<ItemType>* leftPtr)
{
	leftChildPtr = leftPtr;
}  

template<class ItemType>
void Node<ItemType>::setRChild(Node<ItemType>* rightPtr)
{
	rightChildPtr = rightPtr;
} 

template<class ItemType>
Node<ItemType>* Node<ItemType>::getLeftChildPtr() const
{
	return leftChildPtr;
}  		

template<class ItemType>
Node<ItemType>* Node<ItemType>::getRChild() const
{
	return rightChildPtr;
} 		