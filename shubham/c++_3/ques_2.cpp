//To illustrate c++ concept of Polymorphism, Virtual function.

#include <iostream>
using namespace std;

class base {
public:
	virtual void show(void)
	{
		cout << "Base class: Virtual show() function" << endl;
	}

	void display(void)
	{
		cout << "Base class: display() function" << endl;
	}
};

class derived:public base {
public:
	void show(void)
	{
		cout << "Derived class: show() function" << endl;
	}

	void display(void)
	{
		cout << "Derived class: display() function" << endl;
	}
};

int main(void)
{
	base base_object, *ptr;
	ptr = &base_object;

	ptr -> display();
	ptr -> show();

	derived derived_object;
	ptr = &derived_object;

	ptr -> display();
	ptr -> show();

	return 0;
}
