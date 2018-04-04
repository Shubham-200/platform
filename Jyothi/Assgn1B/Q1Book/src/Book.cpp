#include "header.h"
#include "Book.h"

int main(void)
{
	Book b1;

	try{
		if(b1.input()){
			b1.purchase();
		}
	
	}
	catch(char *msg){
		cout << msg << endl;
	}
	
	return EXIT_SUCCESS;
}
