/******************** Operator overloading *************************/

#include <iostream>
#include <stdlib.h>

using namespace std;

class complx{
	private:
	float real;
	float img;

	public:
	void show();
	complx();
	complx(float, float);
	void setComplx(float, float);
	
	complx operator+(complx num);
	complx operator-(complx num);
};

void complx :: show()
{
	cout << " " << real << "+ i" << img << endl;
}

complx:: complx()
{
	real = 0.0;
	img	 = 0.0;
}
complx :: complx(float r, float i)
{
	real = r;
	img	 = i;
}
void complx :: setComplx(float r, float i)
{
	real = r;
	img	 = i;
}

complx complx :: operator+(complx num)
{
	complx tmp;
		
	tmp.real	= real + num.real;
	tmp.img 	= img + num.img;

	return tmp;
}


complx complx :: operator-(complx num)
{
	complx tmp;
		
	tmp.real	= real - num.real;
	tmp.img 	= img - num.img;

	return tmp;
}

int main(void)
{
	complx num1(10, 71), num2(5.7, 66.7);

	cout << "Number 1:";
	num1.show();
	cout << "Number 2:" ;
	num2.show();

	cout << "Number1 + Number2 = " ;
	num1 = num1 + num2 ;
	num1.show();

	cout << "Number1 - Number2 = ";
	num1 = num1 - num2;
	num1.show();

	return 0;
}


