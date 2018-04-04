#include "header.h"

float read_input()
{
	char *input = NULL;
	int index;
	float num;

	try{
		if(NULL == (input = (char *) malloc(sizeof(int) * MAX))){
       		throw "malloc() failed";
    	}

		if(NULL == fgets(input, 32, stdin)){
			throw "fgets() failed";
		}	

		index = 0;
		while(input[index] != '\0')
			index++;

		input[index - 1] = '\0';
			
		num = my_atof(input);

	}
	
	catch(const char *msg){
		free(input);
		input = NULL;

		throw msg;
	}

	free(input);
	input = NULL;

	return num;
}
