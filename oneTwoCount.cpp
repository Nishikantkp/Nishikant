/*
OVERVIEW: Given an Integer Array return the count of one's and two's in a new array of length two.
Ex: input: [1,2,2,1,2,1,2] 
	output: [3,4]
	where 3 is the count of 1's and 4 is the count of 2's

INPUTS: An Integer Array and length of the array 

OUTPUT: An Array with 1's count and 2's count

ERROR CASES: Return NULL for invalid inputs

Difficulty : Very Easy
*/

#include <stdio.h>
int* oneTwoCount(int* input, int length)
{
	if (length > 0)
	{
		static int count[] = { 0, 0 };
		for (int index = 0; index < length; index++)
		{
			if (input[index] == 1)
				count[0]++;
			else if (input[index] == 2)
				count[1]++;
		}
		return count;
	}
	else
		return NULL;
}