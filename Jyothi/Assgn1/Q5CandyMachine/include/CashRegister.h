#include <iostream>
#include <stdlib.h>

using namespace std;

class CashRegister
{
	private:
		int cashOnHand;

	public:
		CashRegister(){
			cashOnHand = 500;
		}

		CashRegister(int cash){
			cashOnHand = cash;
		}

		int getCurrentBalance(){
			return cashOnHand;
		}

		void acceptAmount(int amt){
			cashOnHand += amt;
		}
};
