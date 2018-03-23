
#include <iostream>
#include <string.h>

using namespace std;

class Book{
	private :
	int BookNo;
	char BookTitle[20];
	float Prize;
	float TotalCost(int num);

	public:
	void Input();
	float Purchase();
};

void Book :: Input()
{
	cout << "Enter the Book Number" << endl;
	cin >> BookNo;
	cout << "Enter the Book Title(Max 20 char) " << endl;
	cin >> BookTitle;
	cout << "Enter the Prize of the Book" << endl;
	cin >> Prize;
}

float Book :: TotalCost( int num)
{
	return ( num * Prize);
}

float Book :: Purchase()
{
	int num;
	float totalcost;
	cout << "Enter the Number of copies to be purchased" << endl;
	cin >> num;	
	totalcost = TotalCost(num);
	cout << "Total cost to be Paid := " << totalcost << endl;
	return totalcost;
}

int main( void )
{
	Book obj;

	obj.Input();
	obj.Purchase();
	return 0;
}
