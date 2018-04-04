#include <iostream>

using namespace std;

class sample {
	int x;
	double y;

public:
	sample();
	sample(int);
	sample(int, int);
	sample(int, double);
};

sample::sample()
{
	x = 0;
	y = 0;
	cout << "In constructor 1" << endl;
}

sample::sample(int val)
{
	x = val;
	y = 0;
	cout << "In constructor 2" << endl;
}

sample::sample(int val1, int val2)
{
	x = val1;
	y = val2;
	cout << "In constructor 3" << endl;
}

sample::sample(int val1, double val2)
{
	x = val1;
	y = val2;
	cout << "In constructor 4" << endl;
}

int main(void)
{
	sample obj1;
	sample obj2(2);
	sample obj3(3, 33);
	sample obj4(4, 4.44);

	return 0;
}
