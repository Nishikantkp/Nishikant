/*
OVERVIEW: In a given ascending sorted array, two numbers are changed their position, please fix those two numbers.
E.g.: In [10, 40, 30, 20, 50] 20 and 40 are swapped, so final output will be [10, 20, 30, 40, 50]

INPUTS: Ascending sorted array with two positions swapped, length of the array.

OUTPUT: Update sorted array by fixing swapped numbers.

ERROR CASES: Return NULL for invalid Inputs.

Problem Code :SAP
*/

#include <stdio.h>
void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}

void * sortedArrayPositionsChange(int *Arr, int len)
{
	if (Arr != NULL && len >0)
	{
		int index1 = 0, index2 = 0, count = 0;
		for (int index = 0; index < len; index++)
		{
			if (Arr[index] > Arr[index + 1])
			{

				if (count == 0)
				{
					index1 = index;
					count++;
				}
			}
		}
		int min = Arr[index1 + 1];
		for (int index = index1 + 2; index < len; index++)
		{
			if (Arr[index] < min)
				index2 = index;
		}
		swap(&Arr[index1], &Arr[index2]);
	}
	return NULL;
}