#include "header.h"

template <class myarr>

myarr minimum(myarr arr[], int size)
{
    myarr min = arr[0];

    for(int index = 0; index < size; index++)
        if(arr[index] < min)
            min = arr[index];

    return min;
}

int main(void)
{
	int arr1[] = {5, 25, 112, -6, 45, 4, 2};
	char arr2[] = {'a', '@', '&', 'z', '2'};
	double arr3[] = {5.01, 25.12, 112.46, -6.78, 45.71, 4.91, 2.32};

	int size = sizeof(arr1)/ sizeof(arr1[0]);
	
	cout << "given array";
	for(int index = 0; index < size; index++)
		cout << arr1[index] << "\t";

	cout << "\n";
	cout << "minimum of given int -> " << minimum(arr1, size) << endl; 

	size = sizeof(arr2)/ sizeof(arr2[0]);
	cout << "given array";
	for(int index = 0; index < size; index++)
		cout << arr2[index] << "\t";

	cout << "\n";
	cout << "minimum of given char -> " << minimum(arr2, size) << endl; 

	size = sizeof(arr3)/ sizeof(arr3[0]);
	cout << "given array";
	for(int index = 0; index < size; index++)
		cout << arr3[index] << "\t";

	cout << "\n";
	cout << "minimum of given double -> " << minimum(arr3, size) << endl; 

	return EXIT_SUCCESS;
}
