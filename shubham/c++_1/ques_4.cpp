#include <iostream>
using namespace std;

class Sample
{
	int x;
	double y;

	public:
		Sample()
		{
			x = 0;
			y = 0;	
			cout << "x = " << x << endl;
			cout << "y = " << y << endl;
			cout << "---------------------------------------\n";
		}
		
		Sample(int x1)
		{
			x = x1;
			y = 0;
			cout << "x = " << x << endl;
			cout << "y = " << y << endl;
			cout << "---------------------------------------\n";
		}
		
		Sample(int x1, int y1)
		{
			x = x1;
			y = y1;
			cout << "x = " << x << endl;
			cout << "y = " << y << endl;
			cout << "---------------------------------------\n";
		}

		Sample(int x1, double y1)
		{
			x = x1;
			y = y1;
			cout << "x = " << x << endl;
			cout << "y = " << y << endl;
			cout << "---------------------------------------\n";
		}
};

int main(void)
{
	Sample ob1, ob12(2), ob3(3, 4), ob4(5, 6.5);

	return 0;
}
