#include <iostream>

using namespace std;

template <class X>void fun_swap(X &var1, X &var2)
{
	X temp;
	temp = var1;
	var1 = var2;
	var2 = temp;

}


int main(void)
{
	int ivar1 = 10, ivar2 = 20;
	float fvar1 = 10.75, fvar2 = 20.75;
	char cvar1 = 'a', cvar2 = 'z';
	
	cout << "Variables (of type int, char & float) before swapping" << endl;
	cout << "Interger type:" << endl;
	cout << "\tvariable1\t:=\t" << ivar1 << endl;
	cout << "\tvariable2\t:=\t" << ivar2 << endl;

	cout << "Char type:" << endl;
	cout << "\tvariable1\t:=\t" << cvar1 << endl;
	cout << "\tvariable2\t:=\t" << cvar2 << endl;
	
	cout << "Float type:" << endl;
	cout << "\tvariable1\t:=\t" << fvar1 << endl;
	cout << "\tvariable2\t:=\t" << fvar2 << endl;

	fun_swap(ivar1, ivar2);
	fun_swap(cvar1, cvar2);
	fun_swap(fvar1, fvar2);
	
	cout << "\n";
	cout << "Variables (of type int, char & float) after swapping" << endl;
	cout << "Interger type:" << endl;
	cout << "\tvariable1\t:=\t" << ivar1 << endl;
	cout << "\tvariable2\t:=\t" << ivar2 << endl;

	cout << "Char type:" << endl;
	cout << "\tvariable1\t:=\t" << cvar1 << endl;
	cout << "\tvariable2\t:=\t" << cvar2 << endl;
	
	cout << "Float type:" << endl;
	cout << "\tvariable1\t:=\t" << fvar1 << endl;
	cout << "\tvariable2\t:=\t" << fvar2 << endl;


	return 0;
}
