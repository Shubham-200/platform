#include "header.h"
#include "Salary.h"

void Salary :: getSalaryInfo(void)
{
	cout << "basic pay: " << this -> getBasicPay() << endl;
	cout << "house rent allowance: " << this -> getHRA() << endl;
	cout << "dearness allowance: " << this -> getDA() << endl;
	cout << "provident fund: " << this -> getPF() << endl;
	cout << "net pay: " << this -> getNetPay() << endl;
}
