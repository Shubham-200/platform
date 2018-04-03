/* WAP that defines a function template that returns the smallest value (minimum) in an array of numbers (ints, doubles, floats, unsigned ints */

#include <iostream>
using namespace std;

template <typename X> X smallest(X *arr, int count)
{
	X var;
	var = arr[0];
	for (int i = 1; i < count; i++)
	{
		if (var > arr[i])
			var = arr[i];
	}

	return var;
}

int main(void)
{
	int num[7] = {34, 53, -34, 2, -56, 23, 98};
	double db[7] = {2.45, 6.34, 8.234, 23.45, 3.234, 23.56, 67.234};
	float fl[4] = {23.23, 34.34, 67.56, 2.45};
	unsigned unum[4] = {34, 56, 26, 58};

	int res = smallest(num, 7);
	cout << "smallest integer is " << res << endl;

	double res1 = smallest(db, 7);
	cout << "Smallest double is " << res1 << endl;

	float res2 = smallest(fl, 4);
	cout << "Smallest float is " << res2 << endl;

	unsigned res3 = smallest(unum, 4);
	cout << "Smallest unsigned is " << res3 << endl; 

	return 0;
}
