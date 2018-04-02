#include "header.h"
#include "Salary.h"

bool Employee :: setEmployeeInfo(void)
{
	char *input = NULL;

	try{
		if(NULL == (input = (char*)malloc(sizeof(char *) * MAX))){
			throw "malloc() failed";
		}

		cout << "enter employee num: " ;
		input = read_input(input);	
		if((input == NULL) || (*input == '\0') || (strlen(input) > 10)){
			throw "invalid input";
		}
		this -> setEmpNum(input);
	
		cout << "enter employee name: " ;
		input = read_input(input);	
		if((input == NULL) || (*input == '\0')){
			throw "invalid input";
		}
		this -> setEmpName(input);
	
		cout << "enter employee designation: " ;
		input = read_input(input);	
		if((input == NULL) || (*input == '\0')){
			throw "invalid input";
		}
		this -> setEmpDesig(input);
	}

	catch(const char *msg)
	{
		free(input);
		input = NULL;

		throw msg; 
	}

	free(input);
	input = NULL;

	return true;
}
