#include <iostream>
#include <stdlib.h>
#include <string.h>

#define MAX 12
using namespace std;

class InvalidDate
{
	const char *msg;
	int date;
	public :
	InvalidDate(int dd, const char* str)
	{
		msg = str;
		date = dd;
	}
	void display()
	{
		cout << msg << endl;
		cout << "dd cannot be " << date << endl;
	}
};

class InvalidMnth
{
	const char *msg;
	int mnth;
	public:
	InvalidMnth(int mm, const char *str)
	{
		mnth = mm;
		msg = str;
	}
	void display()
	{
			cout << msg  << endl;
			cout << "mm cannot be " << mnth << endl;
	}
};

void convrt_str_date( char *ptr, int &dd, int &mm, int &yy)
{
	unsigned short int d = 3, m = 3;
	int len;

	len = strlen(ptr);
	
	try {
		
		if( len <= 7 || len >= 11)
			throw len;
	}
	
	catch (int len) {
		cout << "Please follow the format " << endl;
		return;
	}	

	if( len == 9) {
		if(isdigit(*(ptr + 1))) {
			d = 2;
		}
		else {
			m = 2;
		}
	} else if( len == 8) {	
			m = 2;
			d = 2;	
	}
		
	mm = atoi(ptr);
	dd = atoi(ptr + m);
	yy = atoi(ptr + m + d);
}

void isValidDate( char *ptr)
{	
	const char *mnth[12] = { "January", "February", "March", "April", "May", 
								"June", "July", "August", "September", 
									"October", "November", "December" };
	int dd = 0, mm = 0, yy = 0;
		
	convrt_str_date(ptr, dd, mm, yy);
	
	cout << "mm = " << mm << ", dd = " << dd << ", yy = " << yy << endl;
	try {
			if( mm <= 0 || mm >=13 ) {
				throw (InvalidMnth(mm, "Invalid month!!!!"));
			 }else if( mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8
						|| mm == 10 || mm == 12) {
				if( !(dd >= 1 && dd <= 31) )
					throw (InvalidDate(dd, "Invalid date!!!!"));
			} else if( mm == 4 || mm == 6 || mm == 9 || mm == 11 ) {
		
				if( !(dd >= 1 && dd <= 30) )
					throw ( InvalidDate(dd, "Invalid date!!!!"));
			} else if(mm == 2) {
					
				if(dd == 29) {
					if( !(((yy % 4 == 0) && (yy % 100 != 0)) || (yy % 400 == 0)))
					throw ( InvalidDate(dd, "Invalid date!!!!\nIt is not leap year!!!"));
				} else if( !(dd >= 1 && dd <=28)  )
					throw ( InvalidDate(dd, "Invalid date!!!!"));
			}

		}			
				
	catch(InvalidDate date)
	{	
		date.display();
		return;
	}
	catch(InvalidMnth month)
	{
		month.display();
		return;
	}
	

	cout << mnth[mm - 1] << ", " << dd << " " << yy << "." << endl;
}

int main(void)
{
	char *ptr = NULL;

	if(NULL == (ptr = (char *) malloc(sizeof(char) * MAX))) {
		cout << "Malloc error" << endl;
		char arr[MAX];
		ptr = arr;
	}

	cout << "Enter the date (mm/dd/yyyy)\t:\t";
	cin >> ptr;
	isValidDate(ptr);

	return 0;
}
