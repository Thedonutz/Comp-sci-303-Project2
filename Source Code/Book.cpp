#include "Book.h"


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
string Book::getTitle()
{
	return Title;
}