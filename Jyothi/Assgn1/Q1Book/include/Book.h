#include <iostream>
#include <stdlib.h>

using namespace std;

class Book{

	private:
		int bookNo;
		char bookTitle[20];
		float price;
		float totalCost(int noOfCopies);
		
	public:
		void input(void);
		void purchase(void);
};
