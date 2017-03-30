#include "Book.h"


void Book::setISBN(int theISBN)
{
	this->ISBN = theISBN;
}
void Book::setTitle(string theTitle)
{
	this->Title = theTitle;
}
void Book::setRating(rating theRating)
{
	this->theRating = theRating; //place holder
}
int Book::getISBN()
{
	return this->ISBN;
}

rating Book::getTheRating()
{
	return this->theRating; // again, place holder
}
string Book::getTitle()
{
	return this->Title;
}