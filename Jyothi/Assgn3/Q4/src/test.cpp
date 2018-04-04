#include "header.h"

#if 1
void test(int num)
{
	try{
		if(num > 0){
			throw num;
		}

		else{
			throw 'x';
		}
	}
		
	catch(int num){
		cout << "in test() catching num..." << endl;
		cout << num << endl;
	}
	
	catch(char ch){
		cout << "in test() catching char..." << endl;
		cout << ch << endl;
	}

	catch(const char *msg){
		cout << "in test() default exception" << endl;
		cout << msg << endl;	
	}
}
#endif

#if 0
void test(int num)
{
	try{
		if(num > 0){
			throw num;
		}

		else{
			throw 'x';
		}
	}
		
	catch(int num){
		cout << "in test() catching num..." << endl;
		throw num;
	}
	
	catch(char ch){
		cout << "in test() catching char..." << endl;
		throw ch;
	}

	catch(const char *msg){
		cout << "in test() default exception" << endl;
		throw msg; 
	}
}
#endif
