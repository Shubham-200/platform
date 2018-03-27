//This is a student class

#include "header.h"

class student {
	const char *first_name;
	const char *last_name;
	unsigned int age;
	const char *address;
	const char *city;
	unsigned long long phone_no;

public:
	student()
	{
		cout << "Object for class student created" << endl;
	}

	student(const char *fn, const char *ln, unsigned int _age, const char *add, const char *_city, unsigned long long pn)
	{
		first_name = fn;
		last_name = ln;
		age = _age;
		address = add;
		city = _city;
		phone_no = pn;
	
		cout << "Object for class student is created and it's members are initialized" << endl;

	}

	~student()
	{
		cout << "Student object destroyed" << endl;
	}

	void sit_in_class(void)
    {
        cout << "Sitting in main theatre" << endl;
        return;
    }

	void show_first_name (void)
	{
		cout << "The first name of the student is " << first_name << endl;
		return;
	}

	void show_last_name (void)
	{
		cout << "The last name of the student is " << last_name << endl;
		return;
	}
	
	void show_age (void)
	{
		cout << "The age is " << age << endl;
		return;
	}

	void show_address (void)
	{
		cout << "The address is " << address << endl;
		return;
	}

	void show_city (void)
	{
		cout << "The city is " << city << endl;
		return;
	}

	void show_phone_no (void)
	{
		cout << "The phone no. is " << phone_no << endl;
		return;
	}
};

	
