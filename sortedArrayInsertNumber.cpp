/*
OVERVIEW: Given a sorted array, insert a given number into the array at appropriate position.
			E.g.: Arr = [2, 4, 6], num = 5 final Arr = [2, 4, 5, 6]. 5 is inserted at 2nd index.

INPUTS: Integer	Array pointer, length of the array, number to be inserted.

OUTPUT: Array pointer after inserting number.

ERROR CASES: Return NULL for invalid inputs.

NOTES: Use memory allocation techniques to allocate memory.

ProblemCode :SAIN
*/

#include <stdio.h>
#include <malloc.h>

int *sortedArrayInsertNumber(int *Arr, int len, int num)
{
	if (Arr != NULL && len > 0)
	{
		int *temp = (int*)malloc((len + 1)*sizeof(int));

		int index = 0;
		while ((!(num < Arr[index])) && index < len)
		{
			*(temp + index) = Arr[index];
			index++;
		}
		if (index != len - 1)
		{
			*(temp + index) = num;
			index++;
			while (index < len + 1)
			{
				*(temp + index) = Arr[index - 1];
				index++;
			}
		}
		else if (index == len - 1)
		{
			*(temp + (index + 1)) = num;
		}

		Arr = temp;
		return Arr;
	}

	return NULL;

}