
#include <iostream>
using namespace std;

void swap(int &a, int &b)
{
	int temp;
	
	temp = a;
	a = b;
	b = temp;
}

int main(void)
{
	int var1 = 10;
	int var2 = 20;

	cout << "Before calling swap() function" << endl;
	cout << "\n";
	cout << "var1\t:\t" << var1 << endl;
	cout << "var2\t:\t" << var2 << endl;
	cout << "\n";
	
	swap(var1, var2);
	
	cout << "After calling swap() function" << endl;
	cout << "\n";
	cout << "var1\t:\t" << var1 << endl;
	cout << "var2\t:\t" << var2 << endl;
	cout << "\n";

	return 0;
}	
