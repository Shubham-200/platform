//Working of templates

#include <iostream>
using namespace std;

template <typename X> class myclass {
	X var1;
	X var2;
public:
	myclass()
	{
		cout << "Default constructor" << endl;
	}

	myclass(X val1, X val2)
	{
		var1 = val1;
		var2 = val2;
	}

	void getvar(void)
	{
		cout << "Enter first value --> " << endl;
		cin >> var1;

		cout << "Enter second value --> " << endl;
		cin >> var2;

		return;
	} 

	void swap(void)
	{
		X temp;

    	temp = var1;
	    var1 = var2;
    	var2 = temp;

	    return;
	}

	void display(void)
	{
		cout << "variables are --> " << var1 << ", "<< var2 << endl;
		return;
	}
};

int main(void)
{
	myclass<char> obj1;
	cout << "Demonsrating char swap" << endl;
	obj1.getvar();
	obj1.display();
	obj1.swap();
	cout << "After swapping" << endl;
	obj1.display();
	cout << endl;

	myclass<int> obj2;
	cout << "Demonstrating int swap" << endl;
	obj2.getvar();
	obj2.display();
	obj2.swap();
	cout << "After swapping" << endl;
	obj2.display();
	cout << endl;

	myclass<float> obj3;
	cout << "Demonstrating float swap" << endl;
	obj3.getvar();
	obj3.display();
	obj3.swap();
	cout << "After swapping" << endl;
	obj3.display();
	cout << endl;

	return 0;
}


