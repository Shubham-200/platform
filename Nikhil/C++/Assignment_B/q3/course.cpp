#include "course.h"

course :: course()
{
	cout << "Course created without Name" << endl;
	courseName = NULL;
}

course :: course( const char *nam)
{
	cout << "Course created with Name\t:";
	courseName = nam;
	showName();
}

course :: ~course()
{
	cout << "destructor is called for course\t";
	showName();
}

void course :: addStudent(student *s1, student *s2, student *s3)
{
	s[0] = s1;
	s[1] = s2;
	s[3] = s3;
	cout << "Students are added to the course " ;
	showName();
}

void course :: addTeacher(teacher *t1)
{
	t = t1;
	cout << "Teacher added to the course ";
	showName();
}

void course :: showName()
{
	cout << courseName << endl;
}
