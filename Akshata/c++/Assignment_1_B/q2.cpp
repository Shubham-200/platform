#include <iostream>
using namespace std;

class complex
{
	float real;
	float imag;

	public:
			void getValue();
			void display();
			complex operator +(complex c)
			{
				complex res;
				res.real = real + c.real;
				res.imag = imag + c.imag;
				return res;
			}
			
			complex operator -(complex c)
			{
				complex res;
				res.real = real - c.real;
				res.imag = imag - c.imag;
				return res;
			}
};

void complex :: getValue()
{
	cout << "enter the real and imaginary parts respectively:" << endl;
	cin >> real;
	cin >> imag;
}

void complex :: display()
{
	cout << real << "+i" << imag << endl;
}

int main()
{
	complex obj1;
	complex obj2;
	complex result_add;
	complex result_sub;
	
	cout << "get the value for object1 "<< endl;
	obj1.getValue();

	cout << "get the value for object2" << endl;
	obj2.getValue();

	result_add = obj1 + obj2;
	result_sub = obj1 - obj2;

	cout << "object1 : "; 
	obj1.display() ;
	cout << "object2 : ";
	obj2.display() ;
	cout << "Addition : "; 
	result_add.display();
	cout << "substraction : "; 
	result_sub.display();

	return 0;
}
