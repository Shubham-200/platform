#include <iostream>
#include "student.h"
#include "teacher.h"

using namespace std;

class course {
	const char *courseName;
	student *s[3];
	teacher *t;
	
	public:
	course();
	course(const char *);
	~course();
	void show();
	void addStudent(student *, student *, student *);
	void addTeacher(teacher *);
	void showName();
};
