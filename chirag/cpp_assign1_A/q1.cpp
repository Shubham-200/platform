#include <iostream>
#include <limits>

using namespace std;

//Creating class book
class BOOK {
	int BOOK_NO;
	char BOOKTITLE[20];
	float PRICE;
	int TOTAL_COST(int);

public:
	void INPUT();
	void PURCHASE();
};

//Function definition for TOTAL_COST
int BOOK::TOTAL_COST(int i)
{
	int x = 0;
	
	x = PRICE * i;

	return x;
}

//Function definition for INPUT()
void BOOK::INPUT()
{
	while (1) {
		cout << "Enter the book number " << endl;
		cin >> BOOK_NO;

		//Integer validation
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<< "You have entered wrong input" << endl;
			continue;
		}
		break;
	}
	cout << "Enter the title of the book " << endl;
	cin >> BOOKTITLE;

	while(1) {
		cout << "Enter the price of the book " << endl;
		cin >> PRICE;

		//Integer validation
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<< "You have entered wrong input" << endl;
			continue;
		}
		break;
	}
	return;
}

//Function definition for PURCHASE()
void BOOK::PURCHASE(void)
{
	int num_copies = 0;

	while (1) {
		cout << "Enter the number of copies to be purchased" << endl;
		cin >> num_copies;

		//Integer validation
		if(cin.fail())
		{
			cin.clear();
			cin.ignore(numeric_limits<streamsize>::max(), '\n');
			cout<< "You have entered wrong input" << endl;
			continue;
		}
		break;
	}
	int t_cost = TOTAL_COST(num_copies);
	
	cout << "The total cost is " << t_cost << endl;

	return;
}

int main(void)
{
	BOOK mybook;//Creating object for class BOOK

	mybook.INPUT();
	mybook.PURCHASE();

	return 0;
}

		
