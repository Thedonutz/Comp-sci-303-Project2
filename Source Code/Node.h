#ifndef NODE_H
#define NODE_H
using namespace std;

template<class ItemType>
class Node
{
private:
	ItemType item;        
	Node<ItemType>* LChild;   
	Node<ItemType>* RChild;  

public:
	Node();
	Node(const ItemType& anItem);
	Node(const ItemType& anItem,
		Node<ItemType>* leftPtr,
		Node<ItemType>* rightPtr);

	void setItem(const ItemType& anItem);
	void setLChild(Node<ItemType>* leftPtr);
	void setRChild(Node<ItemType>* rightPtr);

	
	ItemType getItem() const;
	Node<ItemType>* getLChild() const;
	Node<ItemType>* getRChild() const;

	bool isLeaf() const;
}; 


#endif 