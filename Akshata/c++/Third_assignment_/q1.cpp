#include <iostream>
using namespace std;

template <class X> void swapargs(X &arg1, X &arg2)
{
	X temp;

	temp = arg1;
	arg1 = arg2;
	arg2 = temp;

}

int main()
{
	int i = 10, j = 20;
	double x = 10.1, y=23.3;
	char a = 'x', b = 'z';

	cout << "before swapping i and j: " << i << ' ' << j << endl;
	cout << "before swapping x and y: " << x << ' ' << y << endl;
	cout << "before swapping a and b: " << a << ' ' << b << endl;

	swapargs(i, j);
	swapargs(x, y);
	swapargs(a, b);

	cout << "after swapping i and j: " << i << ' ' << j << endl;
	cout << "after swapping x and y: " << x << ' ' << y << endl;
	cout << "after swapping a and b: " << a << ' ' << b << endl;
	return 0;
}
