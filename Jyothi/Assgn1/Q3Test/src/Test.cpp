#include "Test.h"

int main(void)
{
	char paper[20] = "C++";
	int marks = 10;

	Test *t1 = new Test();
	cout << "initializing Test()" << endl;
	t1 -> myPrint();

	Test *t2 = new Test(paper);
	cout << "initializing Test(char p[])" << endl;
	t2 -> myPrint();
	
	Test *t3 = new Test(marks);
	cout << "initializing Test(int m)" << endl;
	t3 -> myPrint();
	
	Test *t4 = new Test(paper, marks);
	cout << "initializing Test(char p[], int m)" << endl;
	t4 -> myPrint();
	
	return EXIT_SUCCESS;
}
