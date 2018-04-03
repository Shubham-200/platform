#include <iostream>
#include <stdlib.h>
#include <math.h>
#include <string.h>
using namespace std;

class invalidDay {
  public:
	char str[80];
	int d;

	 invalidDay() {
		*str = 0;
		d = 0;
	} invalidDay(const char *sstr, int i) {
		strcpy(str, sstr);
		d = i;
	}
};

class invalidMonth {
  public:
	char str[80];
	int m;

	 invalidMonth() {
		*str = 0;
		m = 0;
	} invalidMonth(const char *sstr, int i) {
		strcpy(str, sstr);
		m = i;
	}
};

void fun(char arr[10])
{
	int day = 0;
	int month = 0;
	int year = 0;
	int d, m;
	int len;
	int i;

	len = strlen(arr);

	if (len == 10) {
		d = 3;
		m = 3;
	} else if (len == 8) {
		d = 2;
		m = 2;
	} else if (len == 9) {
		if (isdigit(arr[1])) {
			d = 3;
			m = 2;
		} else {
			d = 2;
			m = 3;
		}
	}
	month = atoi(arr);
	day = atoi((arr + d));
	year = atoi((arr + d + m));

	try {
		if (month <= 0 || month > 13)
			throw invalidMonth("invalid month", month);
		else {
			  switch(month)
			  {
			   case 1: if(day >  0 && day <= 31)
			  				cout << "January " << day <<", "<< year << endl;
			   			else
			   				throw invalidDay("invalid day", day);
			   			break;

			   case 2: if(day > 0 && day < 29)
			   				cout << "February " << day <<", "<< year << endl;
			   			else if( day == 29){
			   				if((year % 400 == 0) || (year % 4 == 0) || (!(year % 100)== 0)){
			   					throw invalidDay("noy a leap year", year);
			   				}
			   				else
			   					cout << "February " << day <<", "<< year << endl;
			   			}
			   			else
			   				throw invalidDay("invalid Day",day);
			   			break;

			   case 3: if((day > 0) && (day <= 31))
			   				cout << "March " << day <<", "<< year << endl;
			   			else
			   				throw invalidDay("invalid day", day);
			   			break;

			   case 4: if(day > 0 && day <= 30)
			   				cout << "April " << day <<", "<< year <<endl;
			   			else
			   				throw invalidDay("invalid day", day);
			   			break;

			   case 5: if(day > 0 && day <= 31)
			   				cout << "May " << day <<", "<< year <<endl;
			   			else
			   				throw invalidDay("invalid day", day);
			   			break;

			   case 6: if(day > 0 && day <= 30)
			   				cout << "June " << day <<", "<< year <<endl;
			   			else
			   				throw invalidDay("invalid day", day);
			   			break;

			   case 7: if(day > 0 && day <= 31)
			   				cout << "July " << day <<", "<< year <<endl;
			   			else
			   				throw invalidDay("invalid day", day);
			   			break;

			   case 8: if(day > 0 && day <= 31)
			  				cout << "August " << day <<", "<< year <<endl;
			   			else
			   				throw invalidDay("invalid day", day);
			   			break;

			   case 9: if(day > 0 && day <= 30)
			  				cout << "September " << day <<", "<< year <<endl;
			  			 else
			   				throw invalidDay("invalid day", day);
			   			break;

			   case 10: if(day > 0 && day <= 31)
			   				cout << "October " << day <<", "<< year <<endl;
			  			 else
			   				throw invalidDay("invalid day", day);
			   			break;

			   case 11: if(day > 0 && day <= 30)
			   				cout << "November " << day <<", "<< year <<endl;
			   			else
			   				throw invalidDay("invalid day", day);
			   			break;

			   case 12: if(day > 0 && day <= 31)
			   				cout << "December " << day <<", "<< year <<endl;
			   			else
			   				throw invalidDay("invalid day", day);
			  			 break;
			} 
		}
	}
	catch(invalidMonth mn) {
		cout << mn.str;
		cout << mn.m << endl;
	}
	catch(invalidDay dy) {
		cout << dy.str;
		cout << dy.d << endl;
	}

}

int main()
{
	char *array ;
	if(NULL == (array = (char *) malloc(sizeof(char) * 20))){
		cout << "malloc failed\n";
		return 0;
	}

	cout << "Enter the date of birth in the format (mm-dd-yyyy): ";
	cin >> array;

	fun(array);
	
	free(array);
	return 0;

}
