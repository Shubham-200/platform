#include "header.h"
#include "Course.h"

int main(void)
{
	Student stu1((char *)"Ramu", (char *)"Singh", 20, (char *)"Global edge", (char *)"Hyderabad", (char *)"9874561230");
	Student stu2((char *)"Tommy", (char *)"Patil", 22, (char *)"Mindtree", (char *)"Bangalore", (char *)"9871230456");
	Student stu3((char *)"Shyamu", (char *)"Bhat", 18, (char *)"Accenture", (char *)"Chennai", (char *)"9874560123");
	Teacher teacher((char *)"Zakur", (char *)"Khan", 30,(char *)"Global Village", (char *)"Bangalore", (char *)"9087654123");

	Course intermediate((char*)"C++");
	
	intermediate.addStudent(&stu1, 1);
	intermediate.addStudent(&stu1, 2);
	intermediate.addStudent(&stu1, 3);
	intermediate.addTeacher(&teacher);

	teacher.sitInClass();
	stu1.sitInClass();
	stu2.sitInClass();
	stu3.sitInClass();

	teacher.gradeStudent();

	return EXIT_SUCCESS;
}
