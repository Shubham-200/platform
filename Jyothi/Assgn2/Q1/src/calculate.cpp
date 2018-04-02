#include "header.h"
#include "Salary.h"

float Salary :: calculate(void)
{
	this -> netPay = (this -> getBasicPay()) + (this -> getHRA()) + (this -> getDA()) - (this -> getPF());

	return this -> netPay;
}
