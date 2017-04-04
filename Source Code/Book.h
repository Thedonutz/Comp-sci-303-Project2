#pragma once
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
		string getTitle();
		
		//Rating for Each book Placed in Map. with CustID/Rating the K/V pair.
		map<int, int> getRatingMap();
		void mapPrint(const map<int, int>& map);

};
