class Teacher
{
	private:
		char *firstName;
		char *lastName;
		int age;
		char *address;
		char *city;
		char phoneNo[10];
		
	public:
		Teacher(){
			this -> firstName = NULL;
			this -> lastName = NULL;
			this -> age = 0;
			this -> address = NULL;
			this -> city = NULL;
			strcpy(this -> phoneNo, "");
		}

		Teacher(char *firstName, char *lastName, int age, char *address, char *city, char phoneNo[]){
			this -> firstName = firstName;
			this -> lastName = lastName;
			this -> age = age;
			this -> address = address;
			this -> city = city;
			strcpy(this -> phoneNo, phoneNo);
			cout << "added teacher " << this -> firstName << endl;
		}

		~Teacher(){
			cout << "deleted teacher " << this -> firstName << endl;
		}

		void sitInClass(void);
		void gradeStudent(void);

		char* getFirstName(void){
			return this -> firstName;
		}
};
