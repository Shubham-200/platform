#include <iostream>
using namespace std;

class employee
{
	protected:
		int emp_number;
		char emp_name[20];
		char emp_designation[20];

	public:
		void get_employee_info();
};

class salary : public employee
{
	float basic_pay;
	float hra;
	float da;
	float pf;
	float net_pay;
	
	public:
		void get_salary_info();
		void calculate();
		void display();
};

void employee :: get_employee_info()
{
	cout << "enter the employee number : " << endl;
	cin >> emp_number;

	cout << "enter the employee name : " << endl;
	cin >> emp_name;

	cout << "enter the employee designation : " << endl;
	cin >> emp_designation;
}

void salary :: get_salary_info()
{
	cout << "enter the basic pay of employee : " << endl;
	cin >> basic_pay;

	cout << "enter the hra of employee : " << endl;
	cin >> hra;

	cout << "enter the da of employee : " << endl;
	cin >> da;
	
	cout << "enter the pf of employee : " << endl;
	cin >> pf;
}

void salary :: calculate()
{

	net_pay = basic_pay + hra + da - pf;
	
}

void salary :: display()
{
	cout << "employee number : " << emp_number << endl;	
	cout << "employee name : " << emp_name << endl;	
	cout << "employee designation : " << emp_designation << endl;	
	cout << "basic_pay : " << basic_pay << endl;	
	cout << "hra : " << hra << endl;	
	cout << "da : " << da << endl;	
	cout << "pf : " << pf << endl;	
	cout << "net pay : " << net_pay << endl;
}

int main()
{
	salary s[20];
	int no_of_emp;
	int index;

	cout << "enter the number of employee : " ;
	cin >> no_of_emp;

	for(index = 1 ; index <= no_of_emp ; index++)
	{
		s[index].get_employee_info();
		s[index].get_salary_info();
		s[index].calculate();
		cout << "\n";
	}

	cout << "******EMPLOYEE DETAILS********" << endl;
	for(index = 1 ; index <= no_of_emp ; index++)
	{
		s[index].display();
		cout << "\n";
	}

	return 0;
}

