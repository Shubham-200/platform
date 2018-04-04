#include "header.h"
#include "Complex.h"

void Complex :: set(float real, float imag)
{
	this -> real = real;
	this -> imag = imag;
}

float Complex :: getReal(void)
{
	return this -> real;
}

float Complex :: getImag(void)
{
	return this -> imag;
}
