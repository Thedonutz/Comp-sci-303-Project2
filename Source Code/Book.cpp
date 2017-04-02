#include "Book.h"
#include <iostream>


void Book::setISBN(int theISBN)
{
	ISBN = theISBN;
}
void Book::setTitle(string theTitle)
{
	Title = theTitle;
}
void Book::setRating( int custID, int theRating)
{
	ratingMap.insert (pair<int,int>(custID,theRating)); //place holder
}
int Book::getISBN()
{
	return  ISBN;
}
int Book::getTheRating()
{
	return theRating; // again, place holder
}
map<int, int> Book::getRatingMap()
{
	return ratingMap;
}
string Book::getTitle()
{
	return Title;
}
void Book::mapPrint(const map<int, int>& map)
{
	for (std::map<int, int>::const_iterator it = map.begin(); it != map.end(); it++)
	{
		cout << "Customer ID: " << it->first << endl;
		cout << "Rating Given: " << it->second << endl;
	}
}