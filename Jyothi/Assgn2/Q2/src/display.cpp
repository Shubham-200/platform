#include "header.h"
#include "Derived.h"

void Base :: display(void)
{
	cout << "Base class virtual display()" << endl;
}

void Derived :: display(void)
{
	cout << "Derived class display()" << endl;
}
