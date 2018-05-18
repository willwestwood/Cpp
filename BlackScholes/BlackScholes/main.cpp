#include <iostream>
#include "CallOption.h"
#include "Date.h"

using namespace std;

int main()
{
	//cout << "Call Option Price = " << callOptionPrice(1, 0, 1, 0.05, 0.2, 1) << endl;
	//cout << d.DaysUntil();

	// Declare variables as close to the point of first use as you can.
	Date first(1, 2, 2015);
	//std::cout << "Enter first date: ";
	//std::cin >> first;

	Date second(3, 4, 2017);
	//std::cout << "Enter second date: ";
	//std::cin >> second;

	Date * pDate = NULL;
	std::cout << &pDate << std::endl;
	std::cin >> &pDate;

	std::cout << "Days between the two dates: " << std::abs(first - *pDate) << "\n";

	Date expiry(1, 2, 2019);
	CallOption co(expiry);
	std::cout << co.daysUntilExpiry() << std::endl;

	delete pDate;

	return 0;
}