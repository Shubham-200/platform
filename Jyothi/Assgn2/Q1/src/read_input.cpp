#include "header.h"

char* read_input(char *input)
{
	int index;

	if(NULL == fgets(input, MAX, stdin)){
		throw "fgets() failed";
	}	

	index = 0;
	while(input[index] != '\0')
		index++;

	input[index - 1] = '\0';
	
	return input;
}
