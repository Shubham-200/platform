#include <iostream>
using namespace std;

class base
{
	public:
		virtual void show(){
			cout << "Base class: virtual show() function" <<endl;
		}

		void display(){
			cout << "Base class: display() function" <<endl;
		}
};

class derived : public base
{
	public:
		void show()
		{
			cout << "Derived class: show() function" << endl;
		}
		void display()
		{
			cout << "Derived class: display() function" <<endl;
		}
};

int main()
{
	base base_object;
	base *ptr;
	ptr = &base_object;

	ptr -> display();
	ptr -> show();

	cout << "\n";

	derived derived_object;
	ptr = &derived_object;

	ptr -> display();
	ptr -> show();
	
	return 0;
}
