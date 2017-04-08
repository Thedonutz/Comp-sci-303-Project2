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
	virtual bool insertTitle(Book& item);

	virtual bool insertISBN(Book& item);

	Item_Type find(int& target);

	/*Item_Type find(string& target);*/

private:

	// Private Member Functions
	virtual bool insertByTitle(BTNode<Book>*& local_root,
		Book& item);

	virtual bool insertByISBN(BTNode<Book>*& local_root,
		Book& item);

	Item_Type find(BTNode<Item_Type>* local_root,
		int& target);

	/*Item_Type find(BTNode<Item_Type>* local_root,
		string& target);*/

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
		if (local_root->left == NULL && local_root->right == NULL)
		{
			return (local_root->data);
		}
		if (target < local_root->data.getISBN())
			return find(local_root->left, target);
		else if (local_root->data.getISBN() < target)
			return find(local_root->right, target);
		else
			return (local_root->data);
}
/**
* Will be Added Version 2.0 to Search from String Matching.
*/
//template<typename Item_Type>
//Item_Type Binary_Search_Tree<Item_Type>::find(string& item)
//{
//	return find(this->root, item);
//}
//
//template<typename Item_Type>
//Item_Type Binary_Search_Tree<Item_Type>::find(BTNode<Item_Type>* local_root, string& target)
//{
//	Book temp;
//	bool flag = true;
//	while (flag)
//	{
//		if (local_root == NULL)
//		{
//			cout << " Not Enough Information to Find a Book. " << endl << endl;
//		}
//		if (target == local_root->data.getTitle().substr(0, target.length()))
//		{
//			temp = (local_root->data);
//			flag = false;
//		}
//		else if (target < local_root->data.getTitle().substr(0, target.length()))
//			local_root = local_root->left;
//		else if (local_root->data.getTitle().substr(0, target.length()) < target)
//			local_root = local_root->right;
//		else {
//			temp = (local_root->data);
//			//flag = false;
//		}
//	}
//	return temp;
//}

template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::insertTitle(Book& item) {
		return insertByISBN(this->root, item);
}

template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::insertISBN(Book& item) {
	return insertByISBN(this->root, item);
}

template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::insertByISBN(BTNode<Book>*& local_root, Book& item) {
	if (local_root == NULL) {
		local_root = new BTNode<Item_Type>(item);
		return true;
	}
	else {
		if (item.getISBN() < local_root->data.getISBN())
			return insertByISBN(local_root->left, item);
		else if (local_root->data.getISBN() < item.getISBN())
			return insertByISBN(local_root->right, item);
		else
			return false;
	}
}

template<typename Item_Type>
bool Binary_Search_Tree<Item_Type>::insertByTitle(BTNode<Book>*& local_root, Book& item) {
	if (local_root == NULL) {
		local_root = new BTNode<Item_Type>(item);
		return true;
	}
	else {
		if (item.getTitle() < local_root->data.getTitle())
			return insertByTitle(local_root->left, item);
		else if (local_root->data.getTitle() < item.getTitle())
			return insertByTitle(local_root->right, item);
		else
			return false;
	}
}