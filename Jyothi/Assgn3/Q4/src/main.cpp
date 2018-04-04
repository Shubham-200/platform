#include "header.h"

#if 1
int main(void)
{
	test(10);
	test(0);

	return EXIT_SUCCESS;
}
#endif

#if 0
int main(void)
{
	try{
		test(10);
		test(0);
	}

	catch(int num){
		cout << "in main() catching int..." << endl;
		
		cout << num;

	}

	catch(char ch){
		cout << "in main() catching char..." << endl;

		cout << ch;
	}

	catch(const char *msg){
		cout << "in main()" << endl;
		cout << msg << endl;
	}

	return EXIT_SUCCESS;
}
#endif
