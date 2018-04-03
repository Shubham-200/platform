#include "header.h"
#include "Student.h"
#include "Teacher.h"

void Student :: sitInClass(void)
{
	cout << this -> firstName << " sitting in front of class" << endl;
}

void Teacher :: sitInClass(void)
{
	cout << this -> firstName << " sitting in main theatre" << endl;
}
