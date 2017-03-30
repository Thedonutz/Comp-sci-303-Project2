#pragma once
#include "LibraryTree.h"
#include "Rating.h"
using namespace std;


/*
  Changes:
  1) 'int' -> 'rating' theRating && getTheRating.
*/
struct Book
{
	private:
		
		int ISBN;
		string Title;
	 	rating theRating;
		LibraryTree<TreeNode<rating>> RatingTree();	

	public:
		void setISBN(int theISBN);
		void setTitle(string theTitle);
		void setRating(rating theRating);
		int getISBN();
		rating getTheRating();
		string getTitle();

};
