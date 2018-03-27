
#include "emp.h"
/*
emp :: emp(const char* nam, int num, const char *desig);
{
	name = nam;
	id = num;
	designation = desig;
}
*/
void emp :: get_emp_info()
{
	cout << "Enter employee details" << endl ;
	cout << "Name :\t";
	cin >> name;
	cout << "ID :\t";
	cin >> id;
	cout << "Designation :\t";
	cin >> designation;
}

char * emp :: get_name()
{
	return name;
}

int emp :: get_id()
{
	return id;
}

char * emp :: get_designation()
{
	return designation;
}

void emp :: display()
{
	cout << "Employee Details :"<< endl;
	cout << "Name\t:\t" << name << endl;
	cout << "ID\t:\t" << id << endl;
	cout << "Designation\t:\t" << designation << endl;
}
