#include "header.h"

int main(void)
{
	int num1 = 10;
	int num2 = 20;

	cout << "Before swapping num1 = " << num1 << ", num2 = " << num2 << endl;
	swap(num1, num2);
	cout << "After swapping num1 = " << num1 << ", num2 = " << num2 << endl;

	return EXIT_FAILURE;
}
