#include "Student.h"
#include "Teacher.h"

class Course
{
	private:
		char *courseName;
		Student *stu[3];
		Teacher *teacher;

	public:
		Course(char *courseName){
			this -> courseName = courseName;

			cout << "added course " << this -> courseName << endl;
		}

		void addStudent(Student *stu, int index){
			this -> stu[index] = stu;

			cout << "added student " << stu -> getFirstName() << " to course " << this -> courseName << endl;
		}

		void addTeacher(Teacher *teach){
			teacher = teach;		
			cout << "added teacher " << teach -> getFirstName() << " to course " << this -> courseName << endl;
		}

		~Course(){
			cout << "deleting course " << this -> courseName << endl;
		}

};
