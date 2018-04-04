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
