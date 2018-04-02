#include "Sample.h"

int main(void)
{
	Sample *s1 = new Sample();
	cout << "initializing Sample()" << endl;
	s1 -> myPrint();

	Sample *s2 = new Sample(10);
	cout << "initializing Sample(int x)" << endl;
	s2 -> myPrint();
	
	Sample *s3 = new Sample(10, 20);
	cout << "initializing Sample(int x, int y)" << endl;
	s3 -> myPrint();
	
	Sample *s4 = new Sample(10, 20.56);
	cout << "initializing Sample(int x, double y)" << endl;
	s4 -> myPrint();
	
	return EXIT_SUCCESS;
}
