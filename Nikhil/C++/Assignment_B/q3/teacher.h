

#include <iostream>

using namespace std;

class teacher {
    const char *first;
    const char *last;
    int age;
    const char *addr;
    const char *city;
    long long int phone;

    public :
    teacher();
    teacher(const char *,const char *, int,const  char *,const  char *,
			 long long int);
    ~teacher();
    void setname(const char* , const char*);
    void Sitinclass();
    void show();
    void showName();
	void gradestudent();
};


