#include "header.h"
#include "Book.h"

bool Book :: input(void)
{
	char *input = NULL;
	bool ret = true;
	
	try{
		if(NULL == (input = (char *) malloc(sizeof(int) * MAX))){	
			throw "malloc() failed";
		}

		cout << "enter the book no. :";
		input = read_input(input);	
		bookNo = my_atoi(input);
		
		cout << "enter the book title:";
		input = read_input(input);
		if((input == NULL) || (*input == '\0')){
			throw "invalid input";
		}
		strcpy(bookTitle, input);

		cout << "enter the price:";
		input = read_input(input);	
		price = my_atof(input);

	}
	
	catch(const char *msg){
		cout << msg << endl;
		ret = false;	
	}

	free(input);
	input = NULL;

	return ret;
}
