#include "Rectangle.h"

int main(void)
{
	Rectangle r1;
	Rectangle r2;

	r1.setLength(5);
	r1.setWidth(2.5);
	
	r2.setLength(5);
	r2.setWidth(18.9);

	cout << "Rectangle 1" << endl;
	r1.show();
	
	cout << "Rectangle 2" << endl;
	r2.show();

	if(r1.sameArea(r2)){
		cout << "two rectangles have same area" << endl;

	}else{
		cout << "two rectangle have different area" << endl;
	}

	r1.setLength(15);
	r1.setWidth(6.3);
	r1.show();

	if(r1.sameArea(r2)){
		cout << "two rectangles have same area" << endl;

	}else{
		cout << "two rectangle have different area" << endl;
	}

	return EXIT_SUCCESS;	
}
