#include "header.h"
#include "Complex.h"

void Complex :: display(void)
{
	if(this -> imag < 0)
		cout << this -> real << this -> imag << "i" << endl;

	else
		cout << this -> real << "+" << this -> imag << "i" << endl;
}
