#pragma once

class rating
{
private:
	int CustID;
	int Rating;
public:
	rating(int custID, int rating) { CustID = custID; Rating = rating; }
	int getCustID() { return CustID; }
	int getRating() { return Rating; }
};


