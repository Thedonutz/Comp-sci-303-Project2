#include "LibraryTree.h"
#include "Book.h"
#include <list>
#include <iostream>
#include "Customer.h"
#include <vector>
#include <array>
#include <fstream>
#include <unordered_map>

//using namespace std; // It is not a good practice.

#define STRINGIFY( ... ) #__VA_ARGS__ 

namespace Messages
{

const char *welcome = STRINGIFY(
Hello, Welcome to the Book Center, please, log in to access all the features.
);

const char *Options = STRINGIFY(
%s what would you like to do? (Press the number)\n
1-Logout\n
2-Find Book in Library\n
3-Recommend Books\n
4-See Ratings\n
5-Rate Book\n
);

}

enum class UIOption
{
   LogIn , LogOut , FindBook ,  RecommendBooks , SeeRatings , RateBook , None , Invalid ,
   MIN_OPTION = 1 , MAX_OPTIONS = 5 , 
};

template< typename Type >
static void RequestData( const std::string &message , Type &value )
{
   std::cout << message ;
   std::cin >> value ;
}

namespace Users
{

std::vector< std::array< std::string , 2 > > users = 
{ 
   // Username , Password.
   std::array<std::string,2>{ "murad" , "123" } , 
   std::array<std::string,2>{ "john" , "456" } ,
   std::array<std::string,2>{ "jeff" , "789" }
} ;

int Current = -1 ;

bool Verify( const std::string &username , const std::string &password )
{
  
  int cnt = -1 ;
  for( const auto &user : users )
  {
     ++cnt ;
     if( user[0] == username && user[1] == password )
	 {
	    Current = cnt ;
	    return true ;
	 }
  }  

  return false ;
}

std::string& getUsername( size_t idx )
{
   return users[ idx ][ 0 ] ;
}

std::string& getPassword( size_t idx )
{
   return users[ idx ][ 1 ] ;
}

}

static bool keepOpen = true ;

namespace LoadData
{
   std::vector< Book > books ;
   std::vector< Customer > customers ;

   void debug()
   {
	  printf( "BOOKS INFO:\n" ) ; 
      for( auto &book : books )
	  {
	     printf( "Title: %70s | ISBN: %9d | Rate: %2d\n" , book.getTitle().c_str() , book.getISBN() , book.getTheRating().Rating ) ;
	  }

	  printf( "CUSTOMERS INFO:\n" ) ; 
      for( auto &customer : customers )
	  {
	     printf( "Name: %20s | ID: %2d\n" , customer.getName().c_str() , customer.getId() ) ;
	  }
   
   }

}


int main() 
{
	// LibraryTree<Book> bookTree() ; // NOT used meanwhile.

	//freopen("output.txt", "w", stdout); // Redirect the console output to a file.

	// Load the data 
	// Create a scope too.
    {
		std::ifstream file("books.txt");
		std::string line ; 

		std::getline( file , line ) ; // Skip the first line.

		// With this implementation we can set faster the Rating.
		std::unordered_map< int , size_t > bookMAP ;
		// Map the book id with it index in the vector.

		while( std::getline( file , line ) )
		{
		    const std::string ISBN = line.substr( 0 , 9 ) ;
			const std::string name = line.substr( 10 , line.size() - 1 ) ;

			/* Watch out: using 'int' for ISBN is not a good idea, because if 
			   the ISBN starts with 0, that digit will be lost.
			*/

			const int ISBN_num = std::atoi( ISBN.c_str() ) ;

		    Book book ; 
			book.setISBN( ISBN_num ) ;
			book.setTitle( name ) ;

			bookMAP[ ISBN_num ] = LoadData::books.size() ;

		    LoadData::books.push_back( book ) ;

		}

		file.close() ; 

		file.open( "ratings.txt" ) ; 

		std::getline( file , line ) ; // Skip the first line.

		while( std::getline( file , line ) )
		{
		    const size_t commaPos = line.find( "," ) ;

			const std::string customerID = line.substr( 0 , commaPos ) ;
			const std::string ratingNum = line.substr( commaPos + 1 , commaPos + 2 ) ;
			const std::string ISBN = line.substr( commaPos + 4 , line.size() - 1 ) ;

			const int ISBN_num   = std::atoi( ISBN.c_str() ) ;
			const int customer =  std::atoi( customerID.c_str() ) ;
			const int bookRate   = std::atoi( ratingNum.c_str() ) ;

			const size_t bookIdx = bookMAP[ ISBN_num ] ;

		    LoadData::books[ bookIdx ].setRating( rating( customer , bookRate ) ) ;

		}


		file.close() ;

		file.open( "customers.txt" ) ; 

		std::getline( file , line ) ; // Skip the first line.

		while( std::getline( file , line ) )
		{
		    const size_t commaPos = line.find( "," ) ; // Find where is the ",".
		    const std::string ID = line.substr( 0 , commaPos ) ;
			const std::string name = line.substr( commaPos + 1 , line.size() - 1 ) ;

		    Customer customer ; 
			customer.setId( std::atoi( ID.c_str() ) ) ;
			customer.setName( name ) ;

		    LoadData::customers.push_back( customer ) ;
		}

	}

	// LoadData::debug() ; // Print the data loaded.

	// Give the Welcome message, then ask the user to log in.
	while( true ) 
	{
		std::cout << Messages::welcome << std::endl ;

		std::string username , password ;

		RequestData( "Username:" , username ) ;
		RequestData( "Password:" , password ) ;

		if( Users::Verify( username , password ) ) // If the user is a valid one, go ahead! 
		{
		   break ;
		}
		else // If not, let it try again:
		{
		   std::cout << "Invalid username or password!" << std::endl ;
		}

	}

	while( keepOpen ) 
	{
	    printf( Messages::Options , Users::getUsername( Users::Current ).c_str() ) ;

	    int option = static_cast< int >( UIOption::Invalid ) ;

		RequestData( "Your option is:" , option ) ;

		switch( static_cast< UIOption >( option ) )
		{
			case UIOption::LogOut: 
			     printf( "TODO Log Out\n" ) ;
				 break;
			case UIOption::FindBook: 
			     printf( "TODO Find Book\n" ) ;
			     break;
			case UIOption::RecommendBooks: 
			     printf( "TODO Recommend Books\n" ) ;
			     break;
			case UIOption::SeeRatings: 
			     printf( "TODO See Ratings\n" ) ;
				 break;
			case UIOption::RateBook: 
			     printf( "TODO Rate Book\n" ) ;
				 break;

			default:  
			    std::cout << "Invalid Option, try again" << std::endl ;
			    break;
		}
	
	
	}

	return 0 ;

}

list<Book> RecommendBooks(LibraryTree<Book>& root, list<Customer>& customers, list<Book> recommended )
{
	recommended = {};
	for (list<Customer>::iterator it = customers.begin(); it != customers.end(); it++)
	{
		//TODO
	}
	return recommended;

}