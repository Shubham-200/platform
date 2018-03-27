//Operator overloading to add and subtract Complex numbers

#include <iostream>
#include <limits>
using namespace std;

class overload {
	int var1;
	int var2;

public:
	void getvalue(void)
	{
		while (1) {

			cout << "-->";
			cin >> var1;

			if(cin.fail())
        	{
            	cin.clear();
            	cin.ignore(numeric_limits<streamsize>::max(), '\n');
            	cout<< "You have entered wrong input" << endl;
            	continue;
        	}
	        break;
		}
		
		while (1) {

			cout << "-->";
			cin >> var2;

			if(cin.fail())
	        {
    	        cin.clear();
        	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
            	cout<< "You have entered wrong input" << endl;
	            continue;
    	    }
        	break;
		}
		cout << var1 << " + " << var2 << "i" << endl;
	}

	void display(void)
	{
		cout << var1 << " + " << var2 << "i" << endl;
	}

	overload operator+(overload op2);
	overload operator-(overload op2);
};

overload overload::operator+(overload op2)
{
	overload temp;
	
	temp.var1 = var1 + op2.var1;
	temp.var2 = var2 + op2.var2;

	return temp;
}

overload overload::operator-(overload op2)
{
	overload temp;
	
	temp.var1 = var1 - op2.var1;
	temp.var2 = var2 - op2.var2;

	return temp;
}
int main(void)
{
	overload obj1, obj2, result_add, result_sub;

	cout << "Enter first complex number" << endl;
	obj1.getvalue();
	
	cout << "Enter second complex number" << endl;
	obj2.getvalue();

	result_add = obj1 + obj2;
	result_sub = obj1 - obj2;

	cout << "1st complex number is ";
	obj1.display();
	cout << "2nd complex number is ";
	obj2.display();
	cout << "After adding two complex numbers ";
	result_add.display();
	cout << "After subtracting two complex numbers ";
	result_sub.display();

	return 0;
}
