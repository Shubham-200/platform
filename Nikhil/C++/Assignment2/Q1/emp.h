
#include <iostream>
using namespace std;

class emp
{
	char name[20];
	int id;
	char designation[20];
	
	public:
	void get_emp_info();
	char *get_name();
	int get_id();
	char *get_designation();
	void display();
};

