
/*
OVERVIEW: Given a number N return all the prime numbers upto the integer N.
Ex: input: 10 output: [2,3,5,7] 

INPUTS: An Integer N

OUTPUT: Return an Array of Prime numbers until the number N(N inclusive)

ERROR CASES: Return NULL for invalid inputs

Sample Input : 10
Sample Output : An Array consisting elements {2,3,5,7}
NOTES:

Try to think of a optimized way , and avoid unnecessary comparisons.
*/

#include <stdio.h>
int* nthPrime(int num)
{
	if (num > 0)
	{
		int num1 = 2, output[100], flag;
		int index1 = 0;
		if (num > 2)
		{
			output[0] = 2;
			index1++;
			num1++;
		}

		while (num1 <= num)
		{

			for (int index = 2; index < num1; index++)
			{
				flag = 0;
				if (num1 % index == 0)
					break;
				else
					flag = 1;
			}
			if (flag == 1)
			{
				output[index1] = num1;
				index1++;
			}

			num1++;
		}
		return output;
	}
	return NULL;
}