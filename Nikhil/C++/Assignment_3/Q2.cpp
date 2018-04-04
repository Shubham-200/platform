#include <iostream>

#define NUM 5
using namespace std;

template <class X> X find_smallest(X arr[], int num)
{
	X small;
	int i = 0;
	
	small = arr[i];
	
	for(i = 1 ; i < num; i++)
	{
		if(arr[i] < small)
			small = arr[i];
	}

	return small;
}

int main(void)
{
	int i_arr[NUM] = {10, 20, 5, 15, 1};
	char c_arr[NUM] = { 'z', 'A', 'r', 'a', 'b'};
	float f_arr[NUM] = { 10.75, 20.35, 5.56, 15.76, 0.75};
	int i;	

	cout << "\n";
	cout << "Array of interger: " << endl;
	for( i = 0; i < NUM ; i++)
		cout << i_arr[i] << "\t";
	cout << "\n";
	cout << "\n";
	
	cout << "Array of char: " << endl;
	for( i = 0; i < NUM ; i++)
		cout << c_arr[i] << "\t";
	cout << "\n";
	cout << "\n";
	
	cout << "Array of float: " << endl;
	for( i = 0; i < NUM ; i++)
		cout << f_arr[i] << "\t";
	cout << "\n";
	cout << "\n";
	
	cout << "Smallest element in array of integer\t:=\t" << find_smallest(i_arr, NUM) << endl;
	cout << "Smallest element in array of char\t:=\t" << find_smallest(c_arr, NUM) << endl;
	cout << "Smallest element in array of float\t:=\t" << find_smallest(f_arr, NUM) << endl;
	return 0;
}
