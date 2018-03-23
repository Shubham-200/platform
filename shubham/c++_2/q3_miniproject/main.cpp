//This is main method

#include "course.cpp"

int main(void)
{
	student std1("Chirag", "dg", 21, "bangalore", "rr", 9481820723);
	student std2("qwe", "rt", 22, "asd", "sod", 547845);
	student std3("asdf", "qwef", 34, "ASF", "dtrh", 56786789);

	std3.sit_in_class();
	std1.show_first_name();
	std1.show_phone_no();

	teacher teach1("ram", "she", 50, "kar", "bng", 876);
	teach1.sit_in_class();

	course intercpp("Intermediate C++", std1, std2, std3, teach1);

	intercpp.get_name();

	return 0;
}
