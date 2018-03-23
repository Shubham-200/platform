class student{
	const char *first_name;
	const char *last_name;
	int age;
	const char *address;
	const char *city;
	const char *phone;

	public:
		student( );
		student(const char *fname,const char *lname, int age,const char *addr,const char *city,const char *phone);
		~student();
		void show_student_details();
		void SitInClass();
};
