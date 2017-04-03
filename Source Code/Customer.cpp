#include "Customer.h"
#include <algorithm>

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
void Customer::booksRated(vector<Book> theBookList)
{
	for (vector<Book>::iterator it = theBookList.begin(); it != theBookList.end(); it++)
	{
		Book tempBook = *it;
		map<int, int> tempRating = tempBook.getRatingMap();
		for (std::map<int, int>::const_iterator itr = tempRating.begin(); itr != tempRating.end(); itr++)
		{
			if (itr->first == this->getId())
			{
				bookList.push_back(tempBook);
			}
		}	
	}
}

void Customer::convertList(vector<Book>& bookTitle)
{
	for (vector<Book>::iterator itr = bookTitle.begin(); itr != bookTitle.end(); itr++)
	{
		listTitles.push_back(itr->getTitle());
	}
}
vector<string> Customer::getTitles()
{
	convertList(bookList);
	return listTitles;
}
