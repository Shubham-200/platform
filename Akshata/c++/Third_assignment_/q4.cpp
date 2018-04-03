#include <iostream>
using namespace std;

void test(int value){
	try{
		if(value > 0)
			throw value;
		else
			throw 'x';
	}
	catch(int i){
		cout << "caught an exception: "<< i << endl;
	}
	catch(char a){
		cout << "caught an exception: "<< a <<endl;
	}
}

int main()
{
	test(10);
	test(0);
	test(-2);
	return 0;
}
