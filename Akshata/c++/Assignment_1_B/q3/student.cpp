#include <iostream>
using namespace std;

#include "student.h"

student :: student( )
{
	cout << "student default constructor \n";
	first_name = NULL;
	last_name = NULL;
	age = 0;
	address = NULL;
	city = NULL;
	phone = NULL;
}
		
student :: student(const char *fname,const char *lname, int _age,const char *addr,const char *cit,const char *_phone)
{
	cout << "student object is created " <<fname << endl;
	first_name = fname;
	last_name = lname;
	age = _age;
	address = addr;
	city = cit;
	phone = _phone;
}

student :: ~student()
{
	cout << "destructing the student object\n" ;
}

void student :: show_student_details()
{
	cout << "firstname : " <<first_name << "\n";
	cout << "lastname : " <<last_name << "\n";
	cout << "age : " << age << "\n";
	cout << "address : " << address << "\n";
	cout << "city : " << city << "\n";
	cout << "phone : " << phone << "\n";
}

void student :: SitInClass()
{
	cout << "Sitting in main theatre" << "\n";
}
