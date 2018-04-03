
#include "salary.h"
/*
salary :: salary(float var1, float var2, float var3, float var4)
{
	basic_pay = var1;
	HRA = var2;	
	DA = var3;
	PF = var4;
}
*/
void salary :: get_salary_info()
{
	cout << "Enter the salary info of the Employee " << get_name() << endl;
	cout << "Basic pay\t:\t" ;
	cin >> basic_pay;
	cout << "HRA\t:\t";
	cin >> HRA;
	cout << "DA\t:\t";
	cin >> DA;
	cout << "PF\t:\t";
	cin >> PF;
}

float salary :: calculate() 
{
	net_pay = ( basic_pay + HRA + DA - PF );
}

void salary :: display()
{
	cout << "\n";
    cout << "Name\t\t:\t" << get_name() << endl;
    cout << "ID\t\t:\t" << get_id() << endl;
    cout << "Designation\t:\t" << get_designation() << endl;
	cout << "Salary info is as follows" << endl;
	cout << "Basic pay\t:\t" << basic_pay << endl;
	cout << "HRA\t\t:\t" << HRA << endl;
	cout << "DA\t\t:\t" << DA << endl;
	cout << "PF\t\t:\t" << PF << endl;
	cout << "Net pay\t\t:\t" << net_pay << endl; 	
	cout << "\n";
}

