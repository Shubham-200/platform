#include "header.h"

int main(void)
{
	char num1 = 'a';
	char num2 = 'b';

	cout << "before swapping char " << num1 << "," << num2 << endl;
	swap(num1, num2);
	cout << "After swapping char " << num1 << "," << num2 << endl;

	int num3 = 10;
	int num4 = 20;

	cout << "Before swapping integers " << num3 << "," << num4 << endl;
	swap(num3, num4);
	cout << "After swapping integers " << num3 << "," << num4 << endl;

	double num5 = 15.45;
	double num6 = 20.75;

	cout << "Before swapping double " << num5 << "," << num6 << endl;
	swap(num5, num6);
	cout << "After swapping double " << num5 << "," << num6 << endl;
	
	return EXIT_FAILURE;
}
