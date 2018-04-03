
#include "salary.h"

int main(void)
{
	salary s[20];
	int num = 0;
	int count;

	cout << "Enter the number of employees\t:\t" ;
	cin >> num;	

	count = 0;
	while (count < num)
	{
		s[count].get_emp_info();
		s[count].get_salary_info();
		s[count].calculate();
		count++;
	}	

	cout << "\n" ;	
	cout << "Employee details :" << endl;
	
	count = 0;
	while (count < num)
	{
		s[count].display();
		count++;
	}
	return 0;
}

