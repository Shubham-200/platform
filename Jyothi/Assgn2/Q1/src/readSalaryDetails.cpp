#include "header.h"
#include "Salary.h"

//bool readSalaryDetails(Salary *sal)
bool Salary :: setSalaryInfo(void)
{
	char *input = NULL;

	try{
		if(NULL == (input = (char*)malloc(sizeof(char *) * MAX))){
			throw "malloc() failed";
		}

		cout << "enter basic salary: " ;
		input = read_input(input);	
		this -> setBasicPay(my_atof(input));
	
		cout << "enter HRA: " ;
		input = read_input(input);	
		this -> setHRA(my_atof(input));
	
		cout << "enter DA: " ;
		input = read_input(input);	
		this -> setDA(my_atof(input));

		cout << "enter PF: " ;
		input = read_input(input);	
		this -> setPF(my_atof(input));
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
