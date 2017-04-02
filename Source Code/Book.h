#pragma once
#include "Rating.h"
#include <map>
#include <iostream>
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

		map<int, int> getRatingMap();
		string getTitle();
		void mapPrint(const map<int, int>& map);

};
