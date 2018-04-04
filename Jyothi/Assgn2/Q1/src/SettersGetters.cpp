#include "header.h"
#include "Salary.h"

void Employee :: setEmpNum(char *num)
{
	strcpy(empNum, num);
}

void Employee :: setEmpName(char *name)
{
	strcpy(empName, name);
}

void Employee :: setEmpDesig(char *desig)
{
	strcpy(empDesig, desig);
}

char* Employee :: getEmpNum(void)
{
	return empNum;
}

char* Employee :: getEmpName(void)
{
	return empName;
}

char* Employee :: getEmpDesig(void)
{
	return empDesig;
}

void Salary :: setBasicPay(float basicPay)
{
	this -> basicPay = basicPay;
}

void Salary :: setHRA(float hra)
{
	this -> hra = hra;
}

void Salary :: setDA(float da)
{
	this -> da = da;
}

void Salary :: setPF(float pf)
{
	this -> pf = pf;
}

float Salary :: getBasicPay(void)
{
	return this -> basicPay;
}

float Salary :: getHRA(void)
{
	return this -> hra;
}

float Salary :: getDA(void)
{
	return this -> da;
}

float Salary :: getPF(void)
{
	return this -> pf;
}

float Salary :: getNetPay(void)
{
	return this -> netPay;
}
