class Student
{
	private:
		char *firstName;
		char *lastName;
		short int age;
		char *address;
		char *city;
		char *phoneNo;
		
	public:
		Student(){

			cout << "in default constructor" << endl;
			this -> firstName = NULL;
			this -> lastName = NULL;
			this -> age = 0;
			this -> address = NULL;
			this -> city = NULL;
			this -> phoneNo = NULL;
		}

		Student(char *firstName, char *lastName, int age, char *address, char *city, char *phoneNo){
			
			this -> firstName = firstName;
			this -> lastName = lastName;
			this -> age = age;
			this -> address =  address;
			this -> city = city;
			this -> phoneNo = phoneNo;
			cout << "Adding " << this -> firstName << endl;
		}

		~Student(){
			cout << "deleting " << this -> firstName << endl;
		}

		void sitInClass(void);

		char* getFirstName(void){
			return this -> firstName;
		}
};
