#pragma once
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

	Item_Type find(int& target);
private:

	// Private Member Functions
	virtual bool insert(BTNode<Book>*& local_root,
		Book& item);

	Item_Type find(BTNode<Item_Type>* local_root,
		int& target);

}; // End binary search tree

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