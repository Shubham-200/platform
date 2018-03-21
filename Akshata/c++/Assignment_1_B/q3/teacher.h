class teacher{
	const char *first_name;
	const char *last_name;
	int age;
	const char *address;
	const char *city;
	const char *phone;

	public:
		teacher();
		teacher(const char *fname,const char *lname, int age,const char *addr,const char *city,const char *phone);
		~teacher();
		void show_teacher_details();
		void GradeStudent();
		void SitInClass();
};

