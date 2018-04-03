/* Q-5 Exception Handling */

#include <cctype>
#include <iostream>
#include <cstring>
#include <cstdio>
#include <cstdlib>
#include <bits/stdc++.h>
using namespace std;

class invalidMonth {
public:
	invalidMonth (void)
	{
		cout << "Invalid month, try again" << endl;
	}
};

class invalidDate {
public:
	invalidDate (void)
	{
		cout << "Invalid date, try again" << endl;
	}
};

int main(void)
{
	char *ptr = NULL;
	string mon[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};

	if (NULL == (ptr = (char *)malloc(sizeof(char) * 12))) {
		perror("malloc failed\n");
		return 1;
	}
	
	cout << "Enter your date of birth in format month-date-year" << endl;

	if (NULL == fgets(ptr, 4, stdin)) {
		perror("malloc failed\n");
		return 1;
	}

	int month = 0;

	month = atoi(ptr);

	int singlem = 0;
	int singled = 0;

	if (!isdigit(ptr[1])) {
		singlem = 1;
	}

	try {
		if (month > 12 || month < 0)
			throw invalidMonth();
	}

	catch (invalidMonth e){
		return 1;
	}

	cout << "month = " << month << endl;

	char temp[5];
	int num = 4;

	if (singlem) {
		temp[0] = ptr[2];
		num = 3;
	}

	if (NULL == fgets(ptr, num, stdin)) {
		perror("malloc failed\n");
		return 0;
	}

	int date;
	if (singlem && isdigit(ptr[0])) {
		temp[1] = ptr[0];
		temp[2] = '\0';
		date = atoi(temp);
	}

	else if(singlem && !(isdigit(ptr[0]))) {
		temp[1] = '\0';
		date = atoi(temp);
		singled = 1;
	}
	
	else
		date = atoi(ptr);

	if (!singlem && !isdigit(ptr[1]))
		singled = 1;

	cout << "date = " << date << endl;

	if (singlem)
		temp[0] = ptr[2];

	if (singlem && singled) {
		temp[0] = ptr[1];
		temp[1] = ptr[2];
	}

	if (!singlem && singled) {
		temp[0] = ptr[2];
	}
	
	if (NULL == fgets(ptr, 5, stdin)) {
		perror("malloc failed\n");
		return 1;
	}

	int year = 0;

	if (singled) {
		temp[1] = ptr[0];
		temp[2] = ptr[1];
		temp[3] = ptr[2];
		temp[4] = '\0';
		year = atoi(temp);
	}

	else {
		year = atoi(ptr);
	}

	cout << "year = " << year << endl;

	int lp = 0;

	if (((year % 400) == 0) || ((year % 4) == 0)) {
		cout << year << " is a leap year\n";
		lp = 1;
	}

	else
		cout << year << " is not a leap year\n";

	try {
		int lm = 0;
		if (month == 2 || month == 4 || month == 6 || month == 9 || month == 11)
			lm = 1;

		if (date < 0 || (lm && date > 30) || date > 31)
			throw invalidDate();

		if (month == 2 && lp && date >29)
			throw invalidDate();

		if (month == 2 && !lp && date > 28)
			throw invalidDate();

	}

	catch (invalidDate n) {
		return 0;
	}

	cout << "Your date of birth is " << mon[month -1] << " " << date << ", " << year<< endl;

	return 0;
}
