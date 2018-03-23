
#include "student.h"

student :: student()
{
	cout << "student created with no arguements" << endl;
	first	= NULL;
	last	= NULL;
	age		= 0;
	addr 	= NULL;
	city 	= NULL;
	phone 	= 0;
}

student :: student(const char *fst_name,const char *lst_name, int _age, 
				const char *address, const char *_city, long long int phn)
{
	cout << "student created with arguements" << endl;
	first	= fst_name;
	last	= lst_name;
	age		= _age;
	addr 	= address;
	city 	= _city;
	phone 	= phn;
	show();
}	

student :: ~student()
{
	cout << "destructor is called for student\t" ;
	showName(); 
}	

void student :: setname(const char* fst , const char* lst)
{
	first = fst;
	last = lst;
}

void student :: Sitinclass()
{
	cout << "Sitting in main theater" << endl;
}

void student :: show()
{
	cout << "Name\t: " << first << " " << last << endl;
	cout << "Age\t: " << age << endl;
	cout << "Address\t: " << addr << endl;
	cout << "City\t: " << city << endl;
	cout << "Phone no: " << phone << endl;
}
	
void student :: showName()
{
	cout << "Name\t: " << first << " " << last << endl;
}
