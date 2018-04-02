
#include "class.h"

int main( void )
{
	base *p, b;
	derived d;

	p = &b;
	p->show();
	p->display();

	p = &d;
	p->show();
	p->display();
	
	return 0;
}
