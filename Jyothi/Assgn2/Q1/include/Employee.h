#include "header.h"

class Employee
{
	private:
		char empNum[10];
		char empName[MAX];
		char empDesig[30];

	public:
		void setEmpNum(char *empNum);
		void setEmpName(char *empName);
		void setEmpDesig(char *empDesig);

		char* getEmpNum(void);
		char* getEmpName(void);
		char* getEmpDesig(void);
	
		bool setEmployeeInfo(void);
		void getEmployeeInfo(void);
};
