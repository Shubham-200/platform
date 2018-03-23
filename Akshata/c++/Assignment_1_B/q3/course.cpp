#include <iostream>
using namespace std;

#include "course.h"

course :: course()
{
	cout << "course default constructor\n";
	course_name = NULL;
}

course :: course(const char *c_name)
{
	cout << "course object created " <<c_name <<endl;
	course_name = c_name;
}
void course :: add_student(student *s1, student *s2, student *s3)
{
	cout << "students is added to course " << course_name <<endl;
	stud[0] = s1;
	stud[1] = s2;
	stud[2] = s3;
}

void course :: add_teacher(teacher *t)
{
	cout << "teacher added to course "<< course_name <<endl;
	tech = t;
}

course :: ~course()
{
	cout << "destructing the course object\n";
}

void course :: get_Course_name()
{
	cout << "course name : " << course_name << "\n";
}

