
#include <iostream>
//#include "student.h"
//#include "teacher.h"
#include "course.h"

int main(void)
{

	student student1("Nikhil", "V G", 21, "Global village", "Bangalore", 
						7022340306 );
	cout << "\n";	
	student student2("Chirag", "D G", 21, "Global village", "Bangalore", 
						7899929389 );
	cout << "\n";	

	student student3("Akshatha", "S M", 21, "Global Village", "Bangalore",
						9999888867);
	cout << "\n";	
	
	teacher t1("Mona", "B", 28, "Global Village", "Bangalore", 8159621325);

	course intermediate("C++");
	cout << "\n";	
	intermediate.addStudent(&student1, &student2, &student3);
	cout << "\n";	
	intermediate.addTeacher(&t1);
	cout << "\n";	
	
	cout << "Course Name\t:" ;
	intermediate.showName();
	
	t1.gradestudent();
	cout << "\n";	
	t1.Sitinclass();
	cout << "\n";	
	
	return 0;
}
