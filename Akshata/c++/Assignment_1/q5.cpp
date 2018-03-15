#include <iostream>
#include <stdlib.h>
#include <unistd.h>

using namespace std;

class cashRegister
{
		int cashOnHand;
	
	public:
		cashRegister();
		cashRegister(int);
		int getCurrentBalance();
		void acceptAmount(int);	
};

class dispenserType
{
		int numberOfItems;
		int cost;
	
	public:
		dispenserType();
		dispenserType(int,int);
		int getNoOfItems();
		int getCost();
		int makeSale();
};

cashRegister :: cashRegister()
{
	cashOnHand = 500;	
}

cashRegister :: cashRegister(int money)
{
	cashOnHand = money;
}

int cashRegister :: getCurrentBalance()
{
	return cashOnHand;
}

void cashRegister :: acceptAmount(int money)
{
	cashOnHand = cashOnHand + money;
}

dispenserType :: dispenserType()
{
	numberOfItems = 50;
	cost = 50;
}

dispenserType :: dispenserType(int num, int money)
{
	numberOfItems = num;
	cost = money;
}

int dispenserType :: getNoOfItems()
{
	return numberOfItems;
}

int dispenserType :: getCost()
{
	return cost;
}

int dispenserType :: makeSale()
{
	if (numberOfItems > 0) {
		numberOfItems = numberOfItems - 1;
		return 1;
	}
	else 
		return -1;
}

void sellProduct(dispenserType *item , cashRegister *account)
{
	int money;
	int cost;

	cost  =	item->getCost();
	cout << "Cost of the selected Item is " << cost << endl;
	cout << "Deposit cash to Purchase:\t" << endl;
	cin >> money ;
		
	if( cost == money) {
 		if(item->makeSale() == -1)
			return ;
		else { 
				account->acceptAmount( money );
				cout << "current balance := " << account->getCurrentBalance() << endl;
			}
		}
	else { 
			cout << "Deposited amount is not equal to the Cost of the Item" << endl;
			return;
	}
	return;
}


int showSelection( dispenserType obj[4])
{
	int choice;

	cout << "\n";
	cout << "Item number\t" << "Items\t\t" << "Number of items\t\t" << "Cost\t" << endl;
	cout << "1\t\t" << "gum\t\t" << obj[0].getNoOfItems() << "\t\t\t"<< obj[0].getCost() <<endl;
	cout << "2\t\t" << "chips\t\t"<< obj[1].getNoOfItems() << "\t\t\t"<<obj[1].getCost() <<endl;
	cout << "3\t\t" << "cookies\t\t" << obj[2].getNoOfItems() << "\t\t\t"<<obj[2].getCost() <<endl;
	cout << "4\t\t" << "candies\t\t" << obj[3].getNoOfItems() << "\t\t\t"<<obj[3].getCost() <<endl;
	cout << "\n";

	cout << "*********** Enter your choice ***********" << endl;
	cout << "1.Gum" << endl;
	cout << "2.Chips" << endl;
	cout << "3.Cookies" << endl;
	cout << "4.Candies" << endl;
	cout << "5.Exit" << endl;

	cout << "Your choice\n";
	cin >> choice;	
	
	return choice;
}

void Purchase(dispenserType arr[4], cashRegister account)
{
	int itemNum;

	while(1)
	{
		itemNum = showSelection(arr);
		switch( itemNum )
		{	
			case 1:
					if( arr[0].getNoOfItems() <= 0) {
						cout << "Item is outof stock" << endl;
						break;
					}
					sellProduct(&arr[0], &account);
					break;
			case 2:
					if( arr[1].getNoOfItems() <= 0) {
						cout << "Item is outof stock" << endl;
						break;
					}
					sellProduct(&arr[1], &account);
					break;
			case 3:
					if( arr[2].getNoOfItems() <= 0) {
						cout << "Item is outof stock" << endl;
						break;
					}
					sellProduct(&arr[2], &account);
					break;
			case 4:
					if( arr[3].getNoOfItems() <= 0) {
						cout << "Item is out of stock" << endl;
						break;
					}
					sellProduct(&arr[3], &account);
					break;
			case 5:
					return;
			default:
					cout << "invalid choice" << endl;
		}

	}

}

int main(void)
{
	int choice;
	int itemNum;
	
	cashRegister account;
	dispenserType arr[4];

	while ( 1) {	
		cout << "Enter your choice: " << endl;
		cout << "1. Purchase Items" << endl;
		cout << "2. Exit" << endl;
		cin >> choice;	

		switch( choice )
		{
			case 1:		
					Purchase(arr, account);	
					break;
			case 2:
					exit(0);		
			default : 
					cout << "invalid choice" << endl;
		
		}	
	}
	return 0;
}
