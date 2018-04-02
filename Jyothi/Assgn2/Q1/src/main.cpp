#include "header.h"
#include "Salary.h"

bool readEmpDetails(Employee *);
bool readSalaryDetails(Salary *);

int main(void)
{
	char *input = NULL;
	int noOfEmp;
	
	try{
		if(NULL == (input = (char *) malloc(sizeof(int *) * MAX))){
            throw "malloc() failed";
        }	

		cout << "enter no of employees:" << endl;
		input = read_input(input);
		noOfEmp = my_atoi(input);

		if((noOfEmp > MAX) || (noOfEmp < ONE)){
			cout << "cannot read " << noOfEmp << " details" << endl;
			cout << "out of range" << endl;

			return EXIT_FAILURE;
		}

		Salary s[noOfEmp];

		for(int index = ZERO; index < noOfEmp; index++){
			
			cout << "enter employee" << index + ONE << " details" << endl;
			if(s[index].setEmployeeInfo()){

				cout << "enter " << s[index].getEmpName() << "'s salary details" << endl;
				if(s[index].setSalaryInfo()){
					s[index].calculate();
				}
			}
		}

		for(int index = ZERO; index < noOfEmp; index++){
			cout << "*********************************" << endl;
			s[index].display();
		}		
	}	

	catch(const char *msg)
	{
		cout << msg << endl;
	}

	free(input);
	input = NULL;

	return EXIT_SUCCESS;
}
