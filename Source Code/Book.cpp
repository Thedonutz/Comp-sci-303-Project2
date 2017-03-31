#include "Book.h"


void Book::setISBN(int theISBN)
{
	this->ISBN = theISBN;
}
void Book::setTitle(string theTitle)
{
	this->Title = theTitle;
}
void Book::setRating( int custID, int theRating)
{
	ratingMap.insert (pair<int,int>(custID,theRating)); //place holder
}
int Book::getISBN()
{
	return this->ISBN;
}
int Book::getTheRating()
{
	return this->theRating; // again, place holder
}
string Book::getTitle()
{
	return this->Title;
}