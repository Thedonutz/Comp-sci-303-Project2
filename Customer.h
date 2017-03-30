#ifndef CUSTOMER_H
#define CUSTOMER_H

#include "Book.h"
#include "LibraryTree.h"
#include "Rating.h"
#include <string>
#include <iostream>
using namespace std;

/*
  Changes:
  1) 'int' -> 'rating' theRating && getTheRating.
*/

struct Customer
{

public:

	void setName(string);
	void setId(int);

	string getName();
	int getId();

	void rateBook(int IBSN, rating rating);
	

	
private:

	string name;
	int id;


};
#endif