#include "header.h"
#include "Complex.h"

int main(void)
{
	float real;
	float imag;
	
	Complex obj1;
	Complex obj2;
	Complex resultAdd;
	Complex resultSub;

	try{
		cout << "enter complex number1," << endl;
		cout << "real : ";
		real = read_input();
		cout << "imaginary : ";
		imag = read_input(); 

		obj1.set(real, imag);

		cout << "enter complex number2," << endl;
		cout << "real : ";
		real = read_input();
		cout << "imaginary : ";
		imag = read_input(); 

		obj2.set(real, imag);

		resultAdd = obj1 + obj2;	
		cout << "Addition of two complex nos. : ";
		resultAdd.display();

		resultSub = obj1 - obj2;		
		cout << "Subtraction of two complex nos.: "; 
		resultSub.display();	
	}

	catch(const char *msg){
		cout << msg << endl;
	}
	
	return EXIT_SUCCESS;
}
