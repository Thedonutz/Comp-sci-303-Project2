 #include "Binary_Search_Tree.h"
 #include "Book.h"
 #include <iostream>
 #include "Customer.h"
 #include <vector>
 #include <array>
 #include <fstream>
 #include <unordered_map>

#define STRINGIFY(...) #__VA_ARGS__
vector<string> RecommendBooks(vector<Customer>& customers, int& custID);

namespace Messages
 {
	 const char *welcome = STRINGIFY(
		 Hello, Welcome to the Book Center, please, log in to access all the features.);

		const char *Options = STRINGIFY(
			%s what would you like to do ? (Press the number)\n
			 1 - Logout\n
			 2 - Find Book in Library\n
			 3 - Recommend Books\n
			 4 - See Ratings\n
			 5 - Rate Book\n
			 );
	
		}

enum class UIOption
{
	LogIn, LogOut, FindBook, RecommendBooks, SeeRatings, RateBook, None, Invalid,
		MIN_OPTION = 1, MAX_OPTIONS = 5,
};

template< typename Type >
static void RequestData(const std::string &message, Type &value)
{
	std::cout << message;
	std::cin >> value;
}

namespace Users
{
	std::vector< std::array< std::string, 2 > > users =
	{
		// Username , Password.
		 std::array<std::string, 2>{ "murad", "123" },
		 std::array<std::string, 2>{ "john", "456" },
		 std::array<std::string, 2>{ "jeff", "789" }
	};

	int Current = -1;

	bool Verify(const std::string &username, const std::string &password)
	{
		int cnt = -1;
		for (const auto &user : users)
		{
			++cnt;
			if (user[0] == username && user[1] == password)
			{
				Current = cnt;
				return true;
			}
		}
		return false;
	}

	std::string& getUsername(size_t idx)
	{
		return users[idx][0];
	}
	std::string& getPassword(size_t idx)
	{
		return users[idx][1];
	}

}
static bool keepOpen = true;

namespace LoadData
{
	std::vector< Book > books;
	std::vector< Customer > customers;

	void debug()
	{
		printf("BOOKS INFO:\n");
		for (auto &book : books)
		{
			printf("Title: %70s | ISBN: %9d | Rate: %2d\n", book.getTitle().c_str(), book.getISBN(), book.getTheRating());
		}
		printf("CUSTOMERS INFO:\n");
		for (auto &customer : customers)
		{
			printf("Name: %20s | ID: %2d\n", customer.getName().c_str(), customer.getId());
		}
	}
}


int main()
{
	Binary_Search_Tree<Book> bookTree; //<-This drives everything...

	// Load the data 
	// Create a scope too.
	{
		std::ifstream file("books.txt");
		std::string line;
		std::getline(file, line); // Skip the first line.
		// With this implementation we can set faster the Rating.
		std::unordered_map< int, size_t > bookMAP;
		// Map the book id with it index in the vector.

		while (std::getline(file, line))
		{
			const std::string ISBN = line.substr(0, 9);
			const std::string name = line.substr(10, line.size() - 1);
			/* Watch out: using 'int' for ISBN is not a good idea, because if
			   the ISBN starts with 0, that digit will be lost.
			*/
			const int ISBN_num = std::atoi(ISBN.c_str());
			Book book;
			book.setISBN(ISBN_num);
			book.setTitle(name);
			bookMAP[ISBN_num] = LoadData::books.size();
			LoadData::books.push_back(book);

		}
		file.close();
		file.open("ratings.txt");
		std::getline(file, line); // Skip the first line.

		while (std::getline(file, line))
		{
			const size_t commaPos = line.find(",");
			const std::string customerID = line.substr(0, commaPos);
			const std::string ratingNum = line.substr(commaPos + 1, commaPos + 2);
			const std::string ISBN = line.substr(commaPos + 4, line.size() - 1);
			const int ISBN_num = std::atoi(ISBN.c_str());
			const int customer = std::atoi(customerID.c_str());
			const int bookRate = std::atoi(ratingNum.c_str());
			const size_t bookIdx = bookMAP[ISBN_num];

			LoadData::books[bookIdx].setRating(customer, bookRate);
		}

		file.close();
		file.open("customers.txt");
		std::getline(file, line); // Skip the first line.

		while (std::getline(file, line))
		{
			const size_t commaPos = line.find(","); // Find where is the ",".
			const std::string ID = line.substr(0, commaPos);
			const std::string name = line.substr(commaPos + 1, line.size() - 1);

			Customer customer;
			customer.setId(std::atoi(ID.c_str()));
			customer.setName(name);
			LoadData::customers.push_back(customer);
		}
	}
	//Transfer Data from Murad's Code into scope that's easy to manage;
	vector<Customer> customers = LoadData::customers;
	vector< Book > books = LoadData::books;
	//Loaded Books Along with Rating into Tree ordered.
	for (auto &bookList : books)
	{
		bookTree.insert(bookList);
	}
	//Loads each customer with Vector of books Rated to make recommendations easier.
	for (auto &customerBookList : customers)
	{
		customerBookList.booksRated(books);
	}

	LoadData::debug(); // Print the data loaded.
	// Give the Welcome message, then ask the user to log in.
	while (true)
	{
		std::cout << Messages::welcome << std::endl;
		std::string username, password;

		RequestData("Username:", username);
		RequestData("Password:", password);

		if (Users::Verify(username, password)) // If the user is a valid one, go ahead! 
		{
			break;
		}
		else // If not, let it try again:
		{
			std::cout << "Invalid username or password!" << std::endl;
		}
	}
	while (keepOpen)
	{
		printf(Messages::Options, Users::getUsername(Users::Current).c_str());

		int option = static_cast<int>(UIOption::Invalid);
		int ISBN, custID, myRating;
		char yesNo;
		Book Temp;
		RequestData("Your option is:", option);

		switch (static_cast<UIOption>(option))
		{
		case UIOption::LogOut:
			cout << endl << "See you Next Time! " << endl;
			keepOpen = false;
			break;
		case UIOption::FindBook:
			printf("Enter ISBN of Book you are Looking For. \n");
			cin >> ISBN;
			Temp = bookTree.find(ISBN);
			if (Temp.getISBN() == 0)
				break;
			else
			{
				cout << " Would you like to rate this book? (y/n) " << endl;
				cin >> yesNo;
				switch (yesNo)
				{
				case 'y':
					cout << "::WARNING:: if you already have a Rating, you will add another! " << endl;
					cout << " Enter your Customer ID to rate this Book " << endl;
					cin >> custID;
					if (custID < 10 && custID > -1)
					{
						cout << endl << "Please Enter the rating you wish to give between 1-5: ";
						cin >> myRating;
						customers[custID].rateBook(bookTree, ISBN, myRating);
					}
					else 
						cout << "That ID is not in our System Reverting to Main Menu. " << endl;
					break;
				case 'n':
					break;
				default:
					cout << "Sorry I didn't get that. " << endl;
					break;
				}
			}
			break;
		case UIOption::RecommendBooks:
			cout << " Enter your ID to get the Most current Recommendations: " ;
			cin >> custID;
			if (custID < 10 && custID > -1)
			{
				vector<string> recommendBooks = RecommendBooks(customers, custID);
				for (vector<string>::iterator itr = recommendBooks.begin(); itr != recommendBooks.end(); ++itr) 
				{
					cout << *itr << endl;
				}cout << endl;
			}
			else
			{
				cout << "That ID is not currently Registered at this Library. " << endl << endl;
			}
			break;
		case UIOption::SeeRatings:
			for (auto &bookRatings : books)
			{
				printf("Title: %70s | ", bookRatings.getTitle().c_str());
				cout << endl;
				bookRatings.mapPrint(bookRatings.getRatingMap());
			}
			break;
		case UIOption::RateBook:
			cout << "Enter your Customer ID to rate/rate Again. " << endl;
			cin >> custID;
			if (custID < 10 && custID > -1)
			{
				printf("Enter ISBN of Book you are Looking For. \n");
				cin >> ISBN;
				Temp = bookTree.find(ISBN);
				if (Temp.getISBN() == 0)
					break;
				else
				{
					cout << endl << "Please Enter the rating you wish to give between 1-5: ";
					cin >> myRating;
					customers[custID].rateBook(bookTree, ISBN, myRating);
				}
			}
			else
				cout << "This ID in not in our System. Try again. " << endl;		
			break;
		default:
			std::cout << "Invalid Option, try again" << std::endl;
			break;
		}
	}
	system("pause");
	return 0;
}

vector<string> RecommendBooks(vector<Customer>& customers, int& custID)
{
	vector<string> inCommon, notCommon, holder;
	vector<string> myBooks, otherBooks;
	int customerMostCommon;
	for (int i = 0; i < 10; i++)
	{
		if (customers[i].getId() == custID)
			continue;	
		else
		{
			myBooks = customers[custID].getTitles();
			otherBooks = customers[i].getTitles();
			sort(myBooks.begin(), myBooks.end());
			sort(otherBooks.begin(), otherBooks.end());
			set_intersection(otherBooks.begin(), otherBooks.end(),
				myBooks.begin(), myBooks.end(), back_inserter(holder));
			if (holder.size() > inCommon.size())
			{
				inCommon = holder;
				customerMostCommon = i;
			}
		}
	}
	/**
	* We now have the list from another customer with the most books inCommon.
	* It doesn't matter the Rating for this algorithm. We only care about book Types we like to read.
	* Now we will search the customer with the highest count of like books and recommend the books
	* They have that We don't Have in our List.
	*/
	otherBooks = customers[customerMostCommon].getTitles();
	sort(otherBooks.begin(), otherBooks.end());
	set_difference(otherBooks.begin(), otherBooks.end(),
		myBooks.begin(), myBooks.end(),
		back_inserter(notCommon));
	//This gives duplicates of the differences from each Vector
	//@paramNext we will sort/erase duplicates.
	//@return sort(notCommon.begin(), notCommon.end());
	notCommon.erase(unique(notCommon.begin(), notCommon.end()), notCommon.end());
	return notCommon;
}