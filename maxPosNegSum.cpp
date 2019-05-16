
/*
OVERVIEW: Given an array of integers find the maximum possible sum formed by a positive and the negative
integer in the array.
Ex: input: [1, 9, 8, 2, 3, -1,-10,-5] output: 8 (formed by 9 and -1) 

INPUTS: An Integer array and the length of the array

OUTPUT: Maximum possible sum formed by a positive and the negative integer in the array

ERROR CASES: Return 0 for the invalid inputs

NOTES:
*/

#include <stdio.h>

int returnMin(int *input, int length)
{
	for (int index = 0; index < length; index++)
		if (input[index]< 0)
			return input[index];
}
int maxPosNegSum(int* input, int length)
{
	if (length > 0 && input != NULL && checkArray(input, length))
	{
		int max = 0, min = 0;
		max = input[0];
		min = returnMin(input, 30);
		for (int index = 1; index < length; index++)
		{
			if (input[index] > max)
				max = input[index];
			if (input[index] < 0 && (input[index]) > min)
				min = input[index];
		}
		return  (max + min);
	}
	else
		return 0;
}
int checkArray(int *a, int length)
{
	int checkp = 0, checkn = 0;
	for (int index = 0; index < length; index++)
	{
		if (a[index] > 0)
			checkp = 1;
		if (a[index]<0)
			checkn = 1;

	}
	if (checkp == 1 && checkn == 1)
		return 1;
	else
		return 0;
}