#include <iostream>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>
using namespace std;

class book{
	int book_no;
	char book_title[20];
	float price;
	void total_cost(int n);
	
	public:
		void input();
		void purchase();
};

void book :: total_cost(int n)
{
	cout << "total cost to be paid by the user :" << n * price << "\n";
}

void book :: input()
{
	
	cout << "enter the book number:" << "\n";
	cin >> book_no;
	cout << "enter the book title:" << "\n";
	cin >> book_title;
	cout << "enter the price of the book:" << "\n";
	cin >> price;
	
}

void book :: purchase()
{
	int no_of_copies;
	cout << "enter the number of copies to be purchased.\n";
	cin >>no_of_copies;
	total_cost(no_of_copies);
}

int main()
{
	book b1;
	int choice;
	int b_no;
	char b_title[20];
	float b_price;
	while(1){
	cout << "enter the choice" << "\n" << "1.input" << "\n" \
		<< "2.purchase" <<"\n" <<"3.exit" <<"\n";
	cin >> choice;
	switch (choice)
	{
		case 1 :
				b1.input();

				break;
		case 2:
				if (b_no == 0)
					cout << "no books to purchase" << "\n";
				else
					b1.purchase();
				
				break;

		case 3:
				exit(0);
	}
	}
	return 0;
}
