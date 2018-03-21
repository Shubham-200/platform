#include <iostream>
#include "course.h"

using namespace std;

int main()
{
	student s1("Akshata","Shetty",23,"viveknagar","banglore","9999988888");
	student s2("Ananya","Naik",26,"viveknagar","banglore","9999978888");
	student s3("Divya","V",28,"Rajajinagar","banglore","9999968888");
	
	teacher t("Monalisa","B",46,"vijaynagar","banglore","9999958888");

	course Intermediate("c++");
	
	Intermediate.add_student(&s1, &s2, &s3);

	Intermediate.add_teacher(&t);
	
	Intermediate.get_Course_name();
	
	t.GradeStudent();
	
	t.SitInClass();

}
