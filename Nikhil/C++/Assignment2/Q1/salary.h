

#include "emp.h"

class salary : public emp {
	float basic_pay;
	float HRA;
	float DA;
	float PF;
	float net_pay;
	
	public:
	void get_salary_info();
	float calculate();
	void display();
	
};

//salary :: salary(float var1, float var2, float var3, float var4);
//void salary :: get_salary_info();
//float salary :: calculate();
//void salary :: display();



