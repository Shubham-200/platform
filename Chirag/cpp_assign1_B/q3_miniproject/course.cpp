//This is class course

#include "header.h"
#include "student.cpp"
#include "teacher.cpp"

class course {
	student std[3];
	teacher teach;
	const char *name;

public:
	course()
	{
		cout << "Object course is created" << endl;
	}

	course(const char *name_, student std1, student std2, student std3, teacher teach1)
	{
		std[0] = std1;
		std[1] = std2;
		std[2] = std3;
		teach = teach1;
		name = name_;

		cout << "Object for course is created and it's members are initialized" << endl;

	}

	~course()
	{
		cout << "Object for course is destroyed" << endl;
	}

	void get_name(void)
	{
		cout << "--------->The name of the course is " << name << endl;
		return;
	}

};
