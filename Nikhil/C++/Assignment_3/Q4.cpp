#include <iostream>

using namespace std;

void test(int num)
{
	try {
		
		if( num > 0)
			throw num;
		else
			throw 'x';
	}
	
	catch( int num) {
		cout << "caught an exception (value > 0) \t:\t" << num << endl;
	}
	
	catch(char ch) {
		cout << "caught an exception (value <= 0)\t:\t" << ch << endl;
	}
}

int main(void) 
{
	test(10);
	test(0);
	test(100);
	
	return 0;	

}
