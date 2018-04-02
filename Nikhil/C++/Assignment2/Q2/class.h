
#include <iostream>
using namespace std;

class base {

	public :
	virtual void show();
	virtual void display();
};

class derived : public base {
	
	public :
	void show();
	void display();
};


