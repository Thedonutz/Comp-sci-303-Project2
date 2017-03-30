
#include "BRTree.h"

template<struct Item_Type>
Node<Item_Type>* BRTree<Item_Type>::findNode(Node<Item_Type>* subTreePtr,
	const Item_Type& target) const
{
	
	if (subTreePtr == nullptr)
		return nullptr;                       
	else if (subTreePtr->getItem() == target)
		return subTreePtr;                  
	else if (subTreePtr->getItem() > target)
		return findNode(subTreePtr->getLChild(), target);
	else
		return findNode(subTreePtr->getRChild(), target);
} 

template<class Item_Type>
bool BRTree<Item_Type>::isEmpty() const
{
	return rootPtr == nullptr;
}  

template<class Item_Type>
Item_Type BRTree<Item_Type>::getRootData() 
{
	return rootPtr->getItem();
} 