#pragma once

#include <sstream>
using namespace std;

template<typename Item_Type>
struct TreeNode
{

	Item_Type* data;
	TreeNode<Item_Type>* leftCH;
	TreeNode<Item_Type>* rightCH;

	TreeNode(const Item_Type& the_data,
		TreeNode<Item_Type>* left_val = NULL,
		TreeNode<Item_Type>* right_val = NULL) :
		data(the_data), leftCH(left_val), rightCH(right_val) {}


};