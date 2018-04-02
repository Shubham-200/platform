//WAP to ilustrate c++ concept of inheritance

#include <iostream>
using namespace std;

class emp {
protected:
	unsigned long long emp_number;
	char emp_name[20];
	char emp_designation[20];

public:
	void get_employee_info(void);
};

class salary : public emp {
	unsigned int basic_pay;
	unsigned int net_pay;
	unsigned int HRA;
	unsigned int DA;
	unsigned int PF;

public:
	void get_salary_info(void);
	void calculate(void);
	void display(void);
};

void emp::get_employee_info(void)
{
	cout << "Enter the employee name" << endl;
	cin >> emp_name;

	cout << "Enter the employee number" << endl;
	cin >> emp_number;

	cout << "Enter the employee designation" << endl;
	cin >> emp_designation;
}

void salary::get_salary_info(void)
{
	cout << "Enter the basic pay --> ";
	cin >> basic_pay;

	cout << "Enter the HRA --> ";
	cin >> HRA;

	cout << "Enter the DA --> ";
	cin >> DA;

	cout << "Enter the PF --> ";
	cin >> PF;
}

void salary::calculate(void)
{
	net_pay = basic_pay + HRA + DA - PF;

	cout << "The net pay is " << net_pay << endl;
}

void salary::display(void)
{
	cout << "The name of the employee is --> " << emp_name << endl;
	cout << "The number of the employee is --> " << emp_number << endl;
	cout << "The designation of the employee is --> " << emp_designation << endl;

	cout << "The basic pay is --> " << basic_pay << endl;
	cout << "The net pay is --> " << net_pay << endl;
}

int main(void)
{
	unsigned int num;

	cout << "Enter the number of employees " << endl;
	cin >> num;

	salary s[num];

	for (int i = 0; i < num; i++)
	{
		s[i].get_employee_info();
		s[i].get_salary_info();
		s[i].calculate();

		s[i].display();
		cout << endl;
	}

	return 0;
}
