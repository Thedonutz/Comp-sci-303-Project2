#pragma once
#include "BRTree.h"
#include "Node.h"
#include "Rating.h"
#include <map>
using namespace std;


class Book
{
	private:
		
		int ISBN;
		string Title;
		int customerID;
		int theRating;
		map<int, int> ratingMap;	

	public:
		void setISBN(int theISBN);
		void setTitle(string theTitle);
		void setRating(int custID, int theRating);
		int getISBN();
		int getTheRating();
		string getTitle();

};
