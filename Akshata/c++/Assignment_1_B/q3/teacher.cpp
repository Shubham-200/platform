#include <iostream>
using namespace std;

#include "teacher.h"

teacher::teacher()
{
	cout << "teacher default constructor\n";
	first_name = NULL;
	last_name = NULL;
	age = 0;
	address = NULL;
	city = NULL;
	phone = NULL;
}
		
teacher::teacher(const char *fname,const char *lname, int _age,const char *addr,const char *_city,const char *_phone)
{
	cout << "teacher object is created "<<fname<<endl;
	first_name = fname;
	last_name = lname;
	age = _age;
	address = addr;
	city = _city;
	phone = _phone;
}
teacher ::~teacher()
{
	cout << "destructing the  teacher object\n";
}

void teacher :: show_teacher_details()
{
	cout << "firstname : " <<first_name << "\n";
	cout << "lastname : " <<last_name << "\n";
	cout << "age : " << age << "\n";
	cout << "address : " << address << "\n";
	cout << "city : " << city << "\n";
	cout << "phone : " << phone << "\n";
}

void teacher :: GradeStudent()
{
	cout << "Student graded\n";
}
void teacher :: SitInClass()
{
	cout << "Sitting in front of the class\n";
}

