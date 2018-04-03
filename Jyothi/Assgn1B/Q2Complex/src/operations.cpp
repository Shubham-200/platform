#include "header.h"
#include "Complex.h"

Complex Complex :: operator + (Complex obj2)
{
	Complex resAdd;

	resAdd.real = this -> real + obj2.real;
	resAdd.imag = this -> imag + obj2.imag;

	return resAdd;
}

Complex Complex :: operator - (Complex obj2)
{
	Complex resSub;

	resSub.real = this -> real - obj2.real;
	resSub.imag = this -> imag - obj2.imag;

	return resSub;
}
