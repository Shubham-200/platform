#include "Book.h"

void Book :: purchase(void)
{
	int noOfCopies;

	cout << "enter the number of copies to be purchased :";
	cin >> noOfCopies;

	cout << "total cost : " << totalCost(noOfCopies) << endl;
}
