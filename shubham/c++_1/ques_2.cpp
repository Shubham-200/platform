#include <iostream>
using namespace std;

class Rectangle
{
	float length;
	float width;

	float perimeter(void);
	float area(void);

	public:
		void setlength(float len);
		void setwidth(float wid);
//		float perimeter(void);
//		float area(void);
		void show(void);
	
		int samearea(Rectangle ob2)
		{
			cout << "-------------------------------------------------\n";
			if( this -> area() == ob2.area() )
			{
				cout << "Both the rectanles have same area " << endl;
				return 1;
			}
			else
			{
				cout << "Both the rectangles don't have the same area " << endl;
				return 0;
			}
		}
	
};

void Rectangle::setlength(float len)
{
	length = len;
	
}

void Rectangle::setwidth(float wid)
{
	width = wid;
}

float Rectangle::perimeter(void)
{
	return (2 * (length + width));
}

float Rectangle::area(void)
{
	return (length * width);
}


void Rectangle::show(void)
{
	cout << "-----------------------------------\n";
	cout << "Rectangle perimeter: "<< perimeter() << endl;
	cout << "Rectangle area: "<< area() << endl;
	
}


int main(void)
{
	Rectangle ob1;
	Rectangle ob2;
//	int equal;	

	ob1.setlength(5.0);
	ob1.setwidth(2.5);
	ob2.setlength(5.0);
	ob2.setwidth(18.9);

	ob1.show();
	ob2.show();
	ob1.samearea(ob2);

	cout << "********************************************" << endl;
	ob1.setlength(15);
	ob1.setwidth(6.3);

	ob1.show();
	ob1.samearea(ob2);

	cout << "-----------------------------\n";
	cout << "Thank you\n";

	return 0;
}
