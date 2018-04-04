/* Exception handling */

#include <iostream>
using namespace std;

void test(int i)
{
	try {
		cout << "Inside the try block" << endl;
		if (i > 0)
			throw i;

		else
			throw 'x';
	}

	catch (int i) {
		cout << "Caught an integer exception" << endl;
		cout << "The value is " << i << endl;
	}

	catch (char c) {
		cout << "Caught an character exception" << endl;
		cout << "The value is " << c << endl;
	}

	return;
}

int main(void)
{
	cout << "Inside main" << endl;

	test(10);
	test(0);

	return 0;
}
