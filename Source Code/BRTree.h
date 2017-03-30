#ifndef BRTREE_H
#define BRTREE_H

#include <sstream>
#include <string>
#include "Node.h"
using namespace std;


template<struct Item_Type>
struct BRTree
{
private:
	Node<Item_Type>* rootPtr;

public:

	BRTree();
	BRTree(const Item_Type& rootItem);
	BRTree(const BRTree<Item_Type>& tree);
	 ~BRTree();

	bool isEmpty() const;
	Item_Type getRootData() const;
	Node<Item_Type>* findNode(Node<Item_Type>* treePtr,
		const Item_Type& target) const;

};
#endif
