#include <iostream>

using namespace std;

class student {
	const char *first;
	const char *last;
	int age;
	const char *addr;
	const char *city;
	long long int phone;
	
	public :
	student();
	student(const char *,const char *, int,const  char *,const  char *, long long int);
	~student();
	void setname(const char* , const char*);
	void Sitinclass();
	void show();
	void showName();
};


