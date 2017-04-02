#include "Customer.h"

void Customer::setName(string theName)
{
	this->name = theName;
}

void Customer::setId(int theId)     // set the id of customer
{
	this->id = theId;
}

string Customer::getName()          // returns name of customer
{
	return this->name;
}

int Customer::getId()              // returns id of customer
{
	return this->id;

}

void Customer::rateBook(Binary_Search_Tree<Book>& BookTree, int IBSN, int theRating)
{
	Book hold = BookTree.find(IBSN);
	if (hold.getTheRating() < 1)
	{
		hold.setRating(id , theRating);
	}
	else if (hold.getTheRating() > 1)
	{
		cout << "Would you like to change the rating of this book? Y or N " << endl;
		char answer;
		cin >> answer;
		if (answer == 'Y')
		{
			hold.setRating(id, theRating);
		}
		else if (answer == 'N')
		{
			return;
		}
	}
}

//list<Book> Customer::RecommendBooks(Binary_Search_Tree<Book>& root, list<Customer>& customers, list<Book> recommended)
//{
//	recommended = {};
//	for (list<Customer>::iterator it = customers.begin(); it != customers.end(); it++)
//	{
//		//TODO
//	}
//	return recommended;
//
//}
