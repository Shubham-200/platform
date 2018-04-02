#include "header.h"

double my_atof(char input[])
{
	double num;
	int index;
	short dec = 0;

	try{
		if(input == NULL || input[0] == '\0'){
			throw "invalid input";
		}

		num = 0;
		index = 0;
	
		if((input[0] == '-') || (input[0] == '+')){
			index = 1;	
		}
	
		while(((input[index] >= '0') && (input[index] <= '9')) || ((input[index] == '.') && (dec == 0))){

			if(input[index] == '.'){
				dec = pow(10, index);
			}

			else{
				num = (num * 10) + (input[index] - '0');
			}
		
			index++;
		}

		if(input[index] != '\0'){
			throw "invalid input";
		}

		if(dec != 0){
			num /= dec;
		}
		
		if(input[0] == '-')
			num = 0 - num;

		if((num < INT_MIN) || (num > INT_MAX)){
			throw "out of range";
		}

		return num;
	}

	catch(char *msg){
		throw msg;
	}
}
