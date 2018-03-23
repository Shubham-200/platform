#include <iostream>
using namespace std;

class Complex
{	
	int real;
	int imag;
	
	public:
		void getvalue(int r = 0, int i = 0)
		{
			real = r;
			imag = i;
		}
		
		Complex operator + (Complex const &obj)
		{
			Complex res;

			res.real = real + obj.real;
			res.imag = imag + obj.imag;
	
			return res;
		}

		
		Complex operator - (Complex const &obj)
		{
			Complex res;

			res.real = real - obj.real;
			res.imag = imag - obj.imag;
	
			return res;
		}

		void display_add(void)
		{
			cout << real << "+i" << imag << endl;
		}
	
		void display_sub(void)
		{
			cout << real << "-i" << imag << endl;
		}
};

int main(void)
{
	Complex obj1;
	Complex obj2;
	Complex res_add, res_sub;

	obj1.getvalue(7, 5);
	obj2.getvalue(3, 5);

	res_add = obj1 + obj2;
	res_sub = obj1 - obj2;

	res_add.display_add();
	res_sub.display_sub();

	return 0;
}
