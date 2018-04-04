#include "header.h"
#include "Book.h"

bool Book :: purchase(void)
{
	int noOfCopies;
	char *input = NULL;
	bool ret = true;

    try{
        if(NULL == (input = (char *) malloc(sizeof(int) * MAX))){
            throw "malloc() failed";
        }
	
		cout << "enter the number of copies to be purchased :";
		input = read_input(input);
		noOfCopies = my_atoi(input);

		cout << "total cost : " << totalCost(noOfCopies) << endl;
	}

	catch(const char *msg){
		cout << msg << endl;
		ret = false;
	}

	free(input);
	input = NULL;

	return ret;
}
