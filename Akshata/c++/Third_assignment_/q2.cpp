#include <iostream>
using namespace std;

template <class type> type minimum ( type a[5], int size)
{
	type min;
	int i;
	
	min = a[0];

	for (i = 1 ; i < size ; i++)
	{
		if (min > a[i])
			min = a[i];
	}

	return min;
}

int main()
{
	int a[5] = {2,6,5,1,8};
	double b[7] = { 5,9.0,8.0,2.0,6.3,7.5,1.1};
	float c[5] = {5.3, 9.3, 4.4, 1.5, 0.5};
	unsigned int d[5] = {9, 6, 8, 3, 0};

	int asize, bsize, csize, dsize;

	asize = sizeof(a) / sizeof(int);
	bsize = sizeof(b) / sizeof(double);
	csize = sizeof(c) / sizeof(float);
	dsize = sizeof(d) / sizeof(unsigned int);

	cout << "minimum of araay a: " << minimum(a, asize) << endl;
	cout << "minimum of araay b: " << minimum(b, bsize) << endl;
	cout << "minimum of araay c: " << minimum(c, csize) << endl;
	cout << "minimum of araay d: " << minimum(d, dsize) << endl;

	return 0;
}
