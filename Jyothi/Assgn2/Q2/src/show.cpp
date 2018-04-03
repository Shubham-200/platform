#include "header.h"
#include "Derived.h"

void Base :: show(void)
{
	cout << "Base class virtual show()" << endl;
}

void Derived :: show(void)
{
	cout << "Derived class show()" << endl;
}
