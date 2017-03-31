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

	void rateBook(int IBSN, int rating);
	Book& findBook(int IBSN);
	list<Book> RecommendBooks(Binary_Search_Tree<Book>& root, list<Customer>& customers, list<Book> recommended);

private:

	string name;
	int id;


};
