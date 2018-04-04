//mini project - Candy machine

#include <iostream>
#include <limits>

using namespace std;

class cashregister {
	int cashonhand;

public:
	cashregister()//Default constructor
	{
		cashonhand = 500;
	}

	cashregister(int var)
	{
		cashonhand = var;
	}

	int getcurrentbalance(void)//To get the balance
	{
		return cashonhand;
	}

	void acceptamount(int amount)
	{
		cout << "Amount " << amount << "Rs is accepted" << endl;
		cashonhand += amount;
	}
};

class dispenser {
	int numberofitems;
	int cost;

public:
	dispenser()
	{
		numberofitems = 50;
		cost = 50;
	}

	dispenser(int var, int num)
	{
		numberofitems = var;
		cost = num;
	}

	int getnoitems(void)
	{
		return numberofitems;
	}

	int getcost(void)
	{
		return cost;
	}

	void makesale(void)
	{
		numberofitems -= 1;
	}
};

//Function to select the product
int showselection(void)
{
	while (1)
	{
		int sel = 0;

		while (1) {
			cout << "--------Select any item----------" << endl;
			cout << "1.Candies\n";
			cout << "2.Chips\n";
			cout << "3.Gum\n";
			cout << "4.Cookies\n";

			cin >> sel;
		    if(cin.fail())
		    {
	    	    cin.clear();
    	    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
		        cout<< "You have entered wrong input" << endl;
				continue;
		    }
			break;
		}
	
		if (sel < 5 && sel > 0)
			return sel;

		else
			cout << "Invalid input\n";
	}
}

//Function to sell the product
int sellproduct(dispenser dis, cashregister reg)
{
	if (dis.getnoitems() != 0)
	{
		while(1)
		{
			int amount;

			while (1) {
				cout << "Please enter the amount\n";
				cin >> amount;

			    if(cin.fail())
		    	{
		    	    cin.clear();
    		    	cin.ignore(numeric_limits<streamsize>::max(), '\n');
			        cout<< "You have entered wrong input" << endl;
					continue;
		    	}
				break;
			}

			if (amount >= dis.getcost())
			{
				dis.makesale();
				reg.acceptamount(amount);
				cout << "Please take your product <^><*><^><*><^>\n" << endl;
				break;
			}
			else
				cout << "Amount insufficient\n";
		}
	}
	return 0;
}
	
int main(void)
{
	dispenser candy;
	dispenser chips;
	dispenser gum;
	dispenser cookies;
	cashregister reg;

	while (1)
	{
		int sel = showselection();

		switch (sel)
		{
			case 1:
				if (candy.getnoitems() == 0)
				{
					cout << "No stock for this item\n";
					break;
				}
				cout << "The cost of candy is " << candy.getcost() << endl;
				sellproduct(candy, reg);
				return 0;

			case 2:
				if (chips.getnoitems() == 0)
				{
					cout << "No stock for this item\n";
					break;
				}
				cout << "The cost of chips is " << chips.getcost() << endl;
				sellproduct(chips, reg);
				return 0;

			case 3:
				if (gum.getnoitems() == 0)
				{
					cout << "No stock for this item\n";
					break;
				}
				cout << "The cost of gum is " << gum.getcost() << endl;
				sellproduct(gum, reg);
				return 0;

			case 4:
				if (cookies.getnoitems() == 0)
				{
					cout << "No stock for this item\n";
					break;
				}
				cout << "The cost of cookie is " << cookies.getcost() << endl;
				sellproduct(cookies, reg);
				return 0;
		}
	}

	return 0;
}	
