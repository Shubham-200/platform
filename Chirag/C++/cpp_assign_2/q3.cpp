//Swap two numbers using referance variables.

#include <iostream>
using namespace std;

void swap_numbers(int &var1, int &var2)
{
	int temp;
	
	temp = var1;
	var1 = var2;
	var2 = temp;

	return;
}

int main (void)
{
	int var1, var2;

	cout << "Enter two numbers" << endl;
	cin >> var1;
	cin >> var2;

	cout << "Before swapping --> ";
	cout << var1 << ", " << var2 << endl;

	swap_numbers(var1, var2);

	cout << "After swapping --> " << var1 << ", " << var2 << endl;

	return 0;
}
