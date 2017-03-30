#pragma once
#include <sstream>
#include <string>
#include <cmath>
#include "TreeNode.h"


template<typename Item_Type>
struct LibraryTree
{
public:
	LibraryTree(): root(NULL) {}                                     //default constructor
	LibraryTree(const Item_Type& the_data,
		const LibraryTree<Item_Type>& left_child = LibraryTree(),
		const LibraryTree<Item_Type>& right_child = LibraryTree())    //contructor
		:root(TreeNode<Item_Type>(the_data, left_child.root,
		right_child.root)) {}
	void setSubLeft(TreeNode book);
	void setSubRight(TreeNode book);
	void setRoot(TreeNode<Item_Type> newRoot);

	//TreeNode& getBook;

private:
	TreeNode root;



};
