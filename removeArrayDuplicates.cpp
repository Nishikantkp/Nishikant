/*
OVERVIEW:  given an array that has duplicate values remove all duplicate values.
E.g.: input: [1, 1, 2, 2, 3, 3], output [1, 2, 3]

Ex 2: [4,4,2,2,1,5] output : [4,2,1,5]

INPUTS: Integer array and length of the array .

OUTPUT: Update input array by removing duplicate values and return the final array length

ERROR CASES: Return -1 for invalid inputs.

NOTES: Don't create new array, try to change the input array.
*/
#include<stdio.h>

void swap(int *a, int *b)
{
	int t;
	t = *a;
	*a = *b;
	*b = t;
}
int removeArrayDuplicates(int *Arr, int len)
{
	if (Arr != NULL && len > 0)
	{
		int count = 0;
		for (int index = 0; index < len; index++)
		{
			int temp = Arr[index];
			for (int index1 = index + 1; index1 < len; index1++)
			{
				if (temp == Arr[index1] && Arr[index] != -1)
				{
					count++;
					Arr[index1] = -1;
				}

			}
		}
		for (int index = 1; index < len; index++)
		{
			if ((Arr[index] > -1) && (Arr[index - 1] == -1))
			{
				for (int index1 = index; Arr[index1 - 1] == -1 && index1 - 1 >= -1; index1--)
					swap(&Arr[index1], &Arr[index1 - 1]);
			}
 		}
		return len - count;
	}
	return NULL;
}