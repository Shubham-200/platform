#include "header.h"
#include "Derived.h"

int main(void)
{
	Base *ptr;
	Base b;
	Derived d;

	ptr = &b;
	ptr->show();
	ptr->display();

	ptr = &d;
	ptr->show();
	ptr->display();

	return EXIT_SUCCESS;
}
