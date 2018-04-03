//This is a student class

#include "header.h"

class teacher {
	const char *first_name;
	const char *last_name;
	unsigned int age;
	const char *address;
	const char *city;
	unsigned long long phone_no;

public:
	teacher()
	{
		cout << "Object for class teacher created" << endl;
	}

	teacher(const char *fn, const char *ln, unsigned int _age, const char *add, const char *_city, unsigned long long pn)
	{
		first_name = fn;
		last_name = ln;
		age = _age;
		address = add;
		city = _city;
		phone_no = pn;
	
		cout << "Object for class teacher is created and it's members are initialized" << endl;

	}

	~teacher()
	{
		cout << "Teacher object destroyed" << endl;
	}

	void grade_student(void)
	{
		cout << "Student graded" << endl;
		return;
	}

	void sit_in_class(void)
	{
		cout << "Sitting at front of class" << endl;
		return;
	}

	void show_first_name (void)
	{
		cout << "The first name is " << first_name << endl;
		return;
	}

	void show_last_name (void)
	{
		cout << "The last name is " << last_name << endl;
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
		cout << "The ph no. is " << phone_no << endl;
		return;
	}
};

	
