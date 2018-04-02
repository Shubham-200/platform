#include "header.h"

double my_atoi(char input[])
{
	double num;
	int index;

	try{
		if(input == NULL || input[0] == '\0'){
			throw "invalid input";
		}

		num = 0;
		index = 0;
	
		if((input[0] == '-') || (input[0] == '+')){
			index = 1;	
		}
	
		while((input[index] >= '0') && (input[index] <= '9')){
			num = (num * 10) + (input[index] - '0');
			index++;
		}

		if(input[index] != '\0'){
			throw "invalid input";
		}
	
		if(input[0] == '-')
			num = 0 - num;

		if((num < INT_MIN) || (num > INT_MAX)){
			throw "out of range";
		}

		return num;
	}

	catch(char *msg){
		cout << msg << endl;
	}
}
