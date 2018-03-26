#include <iostream>
#include <limits>

using namespace std;

class rectangle {
	float length;
	float width;

public:
	void setlength();
	void setwidth();
	float perimeter();
	float area();
	void show();
	int samearea(rectangle);
};

//Function definition for setlength
void rectangle::setlength()
{
	float len = 0;

	while (1) {
		cout << "Enter the length" << endl;
		cin >> len;
	
		//Integer validation
	    if(cin.fail())
    	{
	        cin.clear();
    	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	cout<< "You have entered wrong input" << endl;
	        continue;
    	}
		break;
	}
	length = len;
}

//Function definition for setwidth
void rectangle::setwidth()
{
    float wid = 0;

	while (1) {
	    cout << "Enter the width" << endl;
    	cin >> wid;

		//Integer validation
	    if(cin.fail())
    	{
	        cin.clear();
    	    cin.ignore(numeric_limits<streamsize>::max(), '\n');
        	cout<< "You have entered wrong input" << endl;
        	continue;
    	}
		break;
	}

    width = wid;
}

//Function definition for perimeter()
float rectangle::perimeter()
{
	return (2 * length) + (2 * width);
}

float rectangle::area()
{
	return (length * width);
}

void rectangle::show()
{
	cout << "The length of the rectangle is " << length << endl << "The width of the rectangle is " << width << endl;
	
	return;
}

int rectangle::samearea(rectangle rec)
{
	if (rec.area() == area())
		return 1;

	else
		return 0;
}

int main(void)
{
	rectangle rec1, rec2;//Creating objects for class rectangle
	
	cout << "Enter parameters for 1st rectangle " << endl;
	rec1.setlength();
	rec1.setwidth();
	rec1.show();
	cout << "The perimeter of 1st rectangle is " << rec1.perimeter() << endl;
	cout << "The area of 1st rectangle is " << rec1.area() << endl << endl;
	
	cout << "Enter parameters for 2nd rectangle " << endl;
	rec2.setlength();
	rec2.setwidth();
	rec2.show();
	cout << "The perimeter of 2nd rectangle is " << rec2.perimeter() << endl;
	cout << "The area of 2nd rectangle is " << rec2.area() << endl << endl;

	if (rec1.samearea(rec2))
		cout << "Both rectangles have same area" << endl;

	else
		cout << "Rectangles have different area" << endl;

	return 0;
}
