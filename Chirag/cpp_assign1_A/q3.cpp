/*Function overloading is illustrated using the below class
  and also parameter passing to constructors */

#include <iostream>
#include <cstring>

using namespace std;

class Test
{
    char paper[20];
    int marks;

public:
    Test (void)    // Function 1
    {
        strcpy (paper, "Computer");
		cout << "I am fuc 1" << endl;
        marks = 0;
    }
	
    Test (char p[])    // Function 2
    {
        strcpy(paper, p);
		cout << "I am fun 2" << endl;
        marks = 0;
    }
	
    Test (int m)    // Function 3
    {
        strcpy(paper,"Computer");
		cout << "I am fun 3" << endl;
        marks = m;
    }
	
    Test (char p[], int m)    // Function 4
    {
        strcpy (paper, p);
		cout << "I am fun 4" << endl;
        marks = m;
    }
};

int main (void)
{
	char p[20] = "hello";
	Test object1;//Creating objects of class Test
	Test object2(p);
	Test object3(3);
	Test object4(p, 25);

	return 0;
}
