#include <iostream>
#include <cstring>
using namespace std;

class Test
{
	char paper[20];
	int marks;
	
	public:
		Test()
		{
			strcpy(paper, "Computer");
			marks = 0;
			
			cout << "paper = " << paper << endl; 
			cout << "marks = " << marks << endl;
		}	
	
		Test(char p[])
		{
			strcpy(paper, p);
			marks = 0;

			cout << "paper = " << paper << endl;
			cout << "marks = " << marks << endl;
			
		}

		Test(int m)
		{
			strcpy(paper, "Computer");
			marks = m;
			cout << "paper = " << paper << endl;
			cout << "marks = " << marks << endl;
		}

		Test(char p[], int m)
		{
			strcpy(paper, p);
			marks = m;
			cout << "paper = " << paper << endl;
			cout << "marks = " << marks << endl;
		}
};

int main(void)
{
	Test ob1, ob2("C-programming"), ob3(20), ob4("C++", 35);
	
	return 0;
}	
