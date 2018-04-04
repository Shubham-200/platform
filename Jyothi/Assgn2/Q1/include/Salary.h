#include "header.h"
#include "Employee.h"

class Salary : public Employee
{
	private:
		float basicPay;
		float hra;
		float da;
		float pf;
		float netPay;

	public:
		Salary(){
			basicPay = 0.0;
			hra = 0.0;
			da = 0.0;
			pf = 0.0;
			netPay = 0.0;
		}

		~Salary(){
			basicPay = 0.0;
			hra = 0.0;
			da = 0.0;
			pf = 0.0;
			netPay = 0.0;
		}

		void setBasicPay(float basicPay);
		void setHRA(float hra);
		void setDA(float da);
		void setPF(float pf);

		float getBasicPay(void);
		float getHRA(void);
		float getDA(void);
		float getPF(void);
		float getNetPay(void);

		float calculate(void);

		void display(void);

		bool setSalaryInfo(void);
		void getSalaryInfo(void);
};
