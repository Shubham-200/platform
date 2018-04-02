class Book{

	private:
		int bookNo;
		char bookTitle[20];
		float price;
		float totalCost(int noOfCopies);
		
	public:
		bool input(void);
		bool purchase(void);
};
