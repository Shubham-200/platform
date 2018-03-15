#include <iostream>
using namespace std;


class sample {
	private:
    	int x;
	    double y;
	public :
	    sample( ); //Constructor 1
	    sample(int); //Constructor 2
	    sample(int, int); //Constructor 3
	    sample(int, double); //Constructor 4
		void showData();
};

void sample :: showData()
{
	cout << "value of x = " << x << endl;
	cout << "value of y = " << y << endl;
}

sample :: sample( )
{
	x = 0;
	y = 0;
}

sample :: sample(int var)
{
	x = var;
	y = 0;
}

sample :: sample(int var1, int var2)
{
	x = var1;
	y = var2;
}
sample :: sample(int var1, double var2)
{
	x = var1;
	y = var2;
}

int main(void)
{
	sample ob1;
	sample ob2(5);
	sample ob3(6,6);
	sample ob4(7, 7.5);

	cout << "constructor with no arguments" << endl;
	ob1.showData();
	cout << "constructor with one integer argument" << endl;
	ob2.showData();
	cout << "constructor with two integer arguments" << endl;
	ob3.showData();
	cout << "constructor with one interger and one double argument" << endl;
	ob4.showData();

	return 0;
}
