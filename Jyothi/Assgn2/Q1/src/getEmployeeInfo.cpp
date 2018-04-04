#include "header.h"
#include "Employee.h"

void Employee :: getEmployeeInfo()
{
	cout << "Employee number: " << this -> getEmpNum() << endl;
	cout << "Employee name: " << this -> getEmpName() << endl;
	cout << "Employee designation: " << this -> getEmpDesig() << endl;
}
