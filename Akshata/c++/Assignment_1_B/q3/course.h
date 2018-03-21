#include "student.h"
#include "teacher.h"

class course
{
	const char *course_name;
	student *stud[3];
	teacher *tech;

	public : 
		course();
		course(const char *);
		~course();
		void add_student(student* , student*, student*);
		void add_teacher(teacher*);
		void get_Course_name();
};
