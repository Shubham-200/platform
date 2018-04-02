class Complex
{
	private:
		float real;
		float imag;

	public:
		void set(float, float);
		float getReal(void);
		float getImag(void);
		Complex operator + (Complex c2);
		Complex operator - (Complex c2);
		void display(void);	
};
