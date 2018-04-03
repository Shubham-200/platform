template <typename num>

void swap(num num1, num num2)
{
	num1 = num1 ^ num2;
	num2 = num1 ^ num2;
	num1 = num1 ^ num2;
}
