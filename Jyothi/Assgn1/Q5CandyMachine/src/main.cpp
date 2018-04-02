//#include "header.h"
#include "CashRegister.h"
#include "DispenserType.h"

void showSelection(void);
void sellProduct(DispenserType pdt, CashRegister counter);

int main(void)
{
	int choice;
	CashRegister counter;
	DispenserType candy(10, 25);
	DispenserType chips(20, 35);
	DispenserType gum(25, 15);
	DispenserType cookies(30, 12);
	
	while(choice != 5){

		showSelection();
		cin >> choice;

		switch(choice){
			
			case 1:	sellProduct(candy, counter);
					break;
	
			case 2:	sellProduct(chips, counter);
					break;

			case 3:	sellProduct(gum, counter);
					break;

			case 4:	sellProduct(cookies, counter);
					break;

			case 5: return EXIT_SUCCESS;

			default: cout << "invalid choice" << endl;
		}
	}
}
