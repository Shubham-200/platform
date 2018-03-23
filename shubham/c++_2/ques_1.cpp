#include <iostream>
#include <cstdlib>
using namespace std;

class Book
{
	private:
		int book_no;
		char booktitle[20];
		float price;
		double totalcost(int num);
/*{
			return num * price;
		}
*/	
	public:
		void input();
		void purchase();
		
};

void Book::input(void)
{
	cout <<"----------------------------------------\n";
	cout << "Enter the Book No.: ";
	cin >> book_no;
	if(cin.fail())
	{
		cout << "Book number is not valid" << endl;
		exit(EXIT_FAILURE);
	}	
	
	cout << "Enter the Book name: ";
	cin >> booktitle;

	cout << "Enter the price: ";
	cin >> price;
	if(cin.fail())
	{
		cout << "Book price is in invalid format:" << endl;
		exit(EXIT_FAILURE);
	}
}

void Book::purchase(void)
{
	int num;
	
	cout << "Enter the number of books been purchased: ";
	cin >> num;

	if(cin.fail())
	{
		cout << "Enter an integer value :" << endl;
		exit(EXIT_FAILURE);
	}

	cout << "Total cost of the books: "<< totalcost(num) << endl;
	
}

double Book::totalcost(int num)
{
	return (num * price);
}

int main(void)
{
	Book ob1;

	ob1.input();
	ob1.purchase();

	cout <<"Thank you"<<endl;

	return 0;
}
	
