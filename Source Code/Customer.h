#pragma once
#include "Book.h"
#include "Binary_Search_Tree.h"
#include "Rating.h"
#include <string>
#include <list>
#include <iostream>
using namespace std;

struct Customer
{
public:

	void setName(string);
	void setId(int);

	string getName();
	int getId();
	vector<Book> getBooks() { return bookList; }
	vector<string> getTitles();

	void rateBook(Binary_Search_Tree<Book>& BookTree, int IBSN, int theRating);
	void booksRated(vector<Book> theBookList);
	void convertList(vector<Book>& bookTitle);

protected:

	vector<Book> bookList;
	vector<string> listTitles;

private:

	
	string name;
	int id;


};
