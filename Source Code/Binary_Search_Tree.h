#ifndef BINARY_SEARCH_TREE_H
#define BINARY_SEARCH_TREE_H

#include "Binary_Tree.h"
#include "BTNode.h"
#include "Book.h"
using namespace std;

template<typename Item_Type>
class Binary_Search_Tree : public Binary_Tree<Item_Type>
{
public:
	// Constructor
	Binary_Search_Tree() : Binary_Tree<Item_Type>() {}

	// Public Member Functions
	virtual bool insert(Book& item);

	const Item_Type* min() const;

	const Item_Type* min(BTNode<Item_Type>* local_root) const;

	const Item_Type* max() const;

	const Item_Type* max(BTNode<Item_Type>* local_root) const;

	Item_Type find(int& target);
private:

	// Private Member Functions
	virtual bool insert(BTNode<Book>*& local_root,
		Book& item);

	Item_Type find(BTNode<Item_Type>* local_root,
		int& target);

}; // End binary search tree

template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::min() const {
	return min(this->root);
		
}

template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::min(BTNode<Item_Type>* local_root) const{
	if (local_root == NULL)
		return NULL;

		if (local_root->left == NULL)
			return &(local_root->data);
		 return min(local_root->left);
}

template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::max() const {
	return max(this->root);

}

template<typename Item_Type>
const Item_Type* Binary_Search_Tree<Item_Type>::max(BTNode<Item_Type>* local_root) const{
	if (local_root == NULL)
		return NULL;

		if (local_root->right == NULL)
			return &(local_root->data);
		return max(local_root->right);
}



template<typename Item_Type>
Item_Type Binary_Search_Tree<Item_Type>::find(int& item)
{
		return find(this->root, item);
}

template<typename Item_Type>
Item_Type Binary_Search_Tree<Item_Type>::find(BTNode<Item_Type>* local_root, int& target)
{
		if (local_root == NULL) 
		{
			cout << " Book Does Not Exist In our Library " << endl << endl;
			return Book();
		}
		if (target < local_root->data.getISBN())
			return find(local_root->left, target);
		else if (local_root->data.getISBN() < target)
			return find(local_root->right, target);
		else
			return (local_root->data);
}

template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::insert(Book& item) {
		return insert(this->root, item);
}

template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::insert(BTNode<Book>*& local_root, Book& item) {
	if (local_root == NULL) {
		local_root = new BTNode<Item_Type>(item);
		return true;
	}
	else {
		if (item.getISBN() < local_root->data.getISBN())
			return insert(local_root->left, item);
		else if (local_root->data.getISBN() < item.getISBN())
			return insert(local_root->right, item);
		else
			return false;
	}
}

#endif