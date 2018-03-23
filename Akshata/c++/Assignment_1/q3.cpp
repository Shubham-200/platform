/*

	This Q3 will Explain the concept of constructor and function overloading...

*/

#include <iostream>
#include <string.h>
using namespace std;

class Test
{
    char paper[20];
    int marks;
public:
    Test ()    // Function 1
    {
        strcpy (paper, "Computer");
        marks = 0;
    }
	
    Test (char *p)    // Function 2
    {
        strcpy(paper, p);
        marks = 0;
    }
	
    Test (int m)    // Function 3
    {
        strcpy(paper,"Computer");
        marks = m;
    }
	
    Test (char p[], int m)    // Function 4
    {
        strcpy (paper, p);
        marks = m;
    }

	void showData()
	{	
		cout << "paper = " << paper << endl;
		cout << "marks = " << marks << endl;
	}
};

int main(void)
{
	char str1[] = "Maths";
	char str2[] = "Computer science";

    Test ob1;
    Test ob3(99);
    Test ob2(str1);
    Test ob4(str2,100);

    cout << "constructor with no arguments" << endl;
    ob1.showData();
    cout << "constructor with string as argument" << endl;
    ob2.showData();
    cout << "constructor with integer argument" << endl;
    ob3.showData();
    cout << "constructor with one interger and string as argument" << endl;
    ob4.showData();

    return 0;

}

