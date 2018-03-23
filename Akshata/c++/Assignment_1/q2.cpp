#include <iostream>
using namespace std;

class rectangle
{
	float length;
	float width;
	public:
		void setlength(float len);
		void setwidth(float w);
		float perimeter();
		double area();
		void show();
		int sameArea(rectangle r);
};

void rectangle :: setlength(float len)
{
	length = len;
}

void rectangle :: setwidth(float w)
{
	width = w;
}

float rectangle :: perimeter()
{
	return (2 * (length + width) );
}

double rectangle :: area()
{
	return (length * width);
}

void rectangle :: show()
{
	cout << "length of rectangle " << length << endl;
	cout << "width of rectangle " << width << endl;
}

int rectangle :: sameArea(rectangle r)
{
	float a1 = area();
	float a2 = r.area();

	cout << a1 << endl;
	cout << a2 << endl;
	
	if( a1  == a2 )
		return 1;
	else
		return 0;
}

int main()
{
	rectangle r1,r2;
	int result;

	r1.setlength(5);
	r1.setwidth(2.5);
	
	r2.setlength(5);
	r2.setwidth(18.9);
	
	cout << "rectangle1" << endl;
	r1.show();
	cout << "area of rectangle" << r1.area() <<"\n";
	cout << "perimeter of rectangle" << r1.perimeter() << "\n";
	cout <<"\n";	
	cout << "rectangle2" << endl;
	r2.show();
	cout << "area of rectangle"<< r2.area() <<"\n";
	cout << "perimeter of rectangle" << r2.perimeter() << "\n";

	result = r1.sameArea(r2);
		
	if (result)
		cout << "same area" << endl;
	else
		cout << "not same" << endl;
	

	cout << "*-----------------------------------------------------*"<<endl;

	r1.setlength(15);
	r1.setwidth(6.3);
	
	cout << "rectangle1" << endl;
	r1.show();
	cout << "area of rectangle" << r1.area() <<"\n";
	cout << "perimeter of rectangle" << r1.perimeter() << "\n";
	cout << "\n";
	cout << "rectangle2" << endl;
	r2.show();
	cout << "area of rectangle" << r2.area() <<"\n";
	cout << "perimeter of rectangle" << r2.perimeter() << "\n";
	
	result = r1.sameArea(r2);
		
	if (result)
		cout << "same area" << endl;
	else
		cout << "not same" << endl;

	return 0;
}
