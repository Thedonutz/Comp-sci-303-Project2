#pragma once
/** Class for a binary tree. */
#include <cstddef>
#include <sstream>
#include <stdexcept>
#include <string>
#include <iostream>
#include <algorithm>
#include "BTNode.h"
#include <vector>
using namespace std;

template<typename Item_Type>
class Binary_Tree
{
public:
	void setRoot(BTNode<Item_Type>* newRoot);
	BTNode<Item_Type>* getRoot();
	// Constructors and Functions

	/** Construct an empty Binary_Tree. */
	Binary_Tree() : root(NULL) {}

	/** Construct a Binary_Tree with two subtrees.
	@param the_data The data at the root
	@param left_child The left subtree
	@param right_child The right subtree
	*/
	Binary_Tree(const Item_Type& the_data,
		const Binary_Tree<Item_Type>& left_child
		= Binary_Tree(),
		const Binary_Tree<Item_Type>& right_child
		= Binary_Tree()) :
		root(new BTNode<Item_Type>(the_data, left_child.root,
		right_child.root)) {}

	/** Virtual destructor to avoid warnings */
	virtual ~Binary_Tree() {} // Do nothing.


	/** Return the left subtree. */
	Binary_Tree<Item_Type> get_left_subtree() const;

	/** Return the right subtree. */
	Binary_Tree<Item_Type> get_right_subtree() const;

	/** Return the data field of the root.
	@throws std::invalid_argument if empty tree
	*/
	const Item_Type& get_data() const;

	/** Indicate that this is the empty tree. */
	bool is_null() const;

	/** Indicate that this tree is a leaf. */
	bool is_leaf() const;

protected:

	// Protected constructor
	/** Construct a Binary_Tree with a given node as the root */
	Binary_Tree(BTNode<Item_Type>* new_root) : root(new_root) {}

	// Data Field
	BTNode<Item_Type>* root;

};  // End Binary_Tree

template<typename Item_Type>
void Binary_Tree<Item_Type>::setRoot(BTNode<Item_Type>* new_root){

	root = new_root;
}
template<typename Item_Type>
BTNode<Item_Type>* Binary_Tree<Item_Type>::getRoot(){

	return root;
}

// Overloading the ostream insertion operator.
template<typename Item_Type>
std::ostream& operator<<(std::ostream& out,
	const Binary_Tree<Item_Type>& tree)
{
	return out << tree.to_string();
}

// Overloading the istream extraction operator
template<typename Item_Type>
std::istream& operator>>(std::istream& in,
	Binary_Tree<Item_Type>& tree)
{
	tree = Binary_Tree<Item_Type>::read_binary_tree(in);
	return in;
}

// Implementation of member functions


// Accessors
/** Return the left-subtree. */
template<typename Item_Type>
Binary_Tree<Item_Type>
	Binary_Tree<Item_Type>::get_left_subtree() const {
		if (root == NULL) {
			throw std::invalid_argument("get_left_subtree on empty tree");
		}
		return Binary_Tree<Item_Type>(root->left);
}


/** Return the right-subtree */
template<typename Item_Type>
Binary_Tree<Item_Type>
	Binary_Tree<Item_Type>::get_right_subtree() const {
		if (root == NULL) {
			throw std::invalid_argument("get_right_subtree on null tree");
		}
		return Binary_Tree<Item_Type>(root->right);
}

/** Return the data field of the root
@throws std::invalid_argument if null tree
*/
template<typename Item_Type>
const Item_Type& Binary_Tree<Item_Type>::get_data() const {
	if (root == NULL) {
		throw std::invalid_argument("get_data on null tree");
	}
	return root->data;
}

template<typename Item_Type>
bool Binary_Tree<Item_Type>::is_null() const {
	return root == NULL;
}

/** Indicate that this tree is a leaf. */
template<typename Item_Type>
bool Binary_Tree<Item_Type>::is_leaf() const {
	if (root != NULL) {
		return root->left == NULL && root->right == NULL;
	}
	else
		return true;
}