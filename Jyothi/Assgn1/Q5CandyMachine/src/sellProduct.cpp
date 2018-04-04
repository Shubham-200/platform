#include "DispenserType.h"
#include "CashRegister.h"

void sellProduct(DispenserType pdt, CashRegister counter)
{
	int amt;
	int remAmt;

	if(pdt.getNoOfItems() > 0){
		cout << "Please deposit Rs." << pdt.getCost() << endl;
		cin >> amt;

		if(amt < pdt.getCost()){
			cout << "Please deposit another Rs." << pdt.getCost() - amt << endl;
			cin >> remAmt;
			amt += remAmt;
		}

		if(amt >= pdt.getCost()){
			counter.acceptAmount(amt);
			pdt.makeSale();
			cout << "collect your candy" << endl;
			cout << "Thank you" << endl;
		}

		else{
			cout << "the amount is not enough" << endl;
			cout << "collect the cash" << endl;
		}
	}

	else{
		cout << "sorry! item out of stock" << endl;
	}
}
