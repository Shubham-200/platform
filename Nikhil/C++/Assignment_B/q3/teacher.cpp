#include "teacher.h"

teacher :: teacher()
{
    cout << "teacher created with no arguements" << endl;
    first   = NULL;
    last    = NULL;
    age     = 0;
    addr    = NULL;
    city    = NULL;
    phone   = 0;
}

teacher :: teacher(const char *fst_name,const char *lst_name, int _age,
                const char *address, const char *_city, long long int phn)
{
    cout << "teacher created with arguements" << endl;
    first   = fst_name;
    last    = lst_name;
    age     = _age;
    addr    = address;
    city    = _city;
    phone   = phn;
    show();
}

teacher :: ~teacher()
{
    cout << "destructor is called for teacher\t" ;
    showName();
}

void teacher :: setname(const char* fst , const char* lst)
{
    first = fst;
    last = lst;
}

void teacher :: Sitinclass()
{
	cout << "Sitting at front of class" << endl;
}

void teacher :: show()
{
    cout << "Name\t: " << first << " " << last << endl;
    cout << "Age\t: " << age << endl;
    cout << "Address\t: " << addr << endl;
    cout << "City\t: " << city << endl;
    cout << "Phone no: " << phone << endl;
}

void teacher :: showName()
{
    cout << "Name\t: " << first << " " << last << endl;
}

void teacher :: gradestudent()
{
	cout << "Student graded " << endl;	
}
