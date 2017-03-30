#pragma once

// Class -> Struct.
// Add a constructor.

struct rating
{
	int CustID;
	int Rating;

	rating( int customerID , int Rate )
	{
	  CustID = customerID ; 
	  Rating = Rate ;
	}
	
	rating()
	{
	  CustID = 0 ;
	  Rating = 0 ;
	}

};


