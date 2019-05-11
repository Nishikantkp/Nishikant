/*Problem - Swapping bits in a given number.

Aim: A positive number is given as input along with two positions p1, p2 and length n. Your job is to write a program that swaps 'n' bits of the number starting from positions p1,p2. p1, p2 are 0-indexed values that start from least significant bit of the number.
	 Use unsigned int data type.

Explanation:
Sample 1: number = 47. Its binary representation is 00101111
          p1 = 1 (Start from 2nd bit from right side)
          p2 = 5 (Start from 6th bit from right side)
          n = 3 (No of bits to be swapped)
          The 3 bits starting from p1 are 00101'111' and the 3 bits staring from p2 are '001'01111. After swapping these two, the resultant binary string will be 1110011
          which is equal to decimal value 227.
          Hence the output must be 227.
          
Sample 2: number = 28. Its binary representation is 11100
          p1 = 0 (Start from 1st bit from right side)
          p2 = 3 (Start from 4th bit from right side)
          n = 2 (No of bits to be swapped)
          The 2 bits starting from p1 are 111'00' and the 2 bits staring from p2 are '11'100. After swapping these two, the resultant binary string will be 00111.
          which is equal to decimal value 7.
          Hence the output must be 7.

Sample 3: number=178. Its binary representation is 10110010.
		  p1=0  (Start from 1st bit from right side)
		  p2=30 (Start from 31st bit from right side)
	      n=5   (No of bits to be swapped)
		  In this case, since range exceeds at position2, use 0's in that case. So, the bits starting from p1 are '10010' and the bits staring from p2 are '00000'.
		  After swapping the two, the resultant binary string will be '10010000000000000000000000010100000'.But considering only 32 bits, dicsard extra bits 
		  on left side and hence resultant string will be '10000000000000000000000010100000' which is equal to decimal value 2147483808
	      Hence the output must be 2147483808.


Constraints:
1) The positions and the length 'n' must always be positive.
2) 0<=p1<p2<=32.
3) If the range overflows 32, discard the extra bits.(See Sample 3)
2) It is guaranteed that positions and ranges will not overlap.
3) It is guaranteed that the number will not exceed 32 bit range. 

Note: If constraints are violated, then return 0.
      Please Use 32 bit data(unsigned int) type to get accurate results.

	  DONT CHANGE THE FUNCTION HEADERS.

*/

#include<stdio.h>


unsigned int swapBits(unsigned int number, int p1, int p2, int n)
{
	if (n > 0 && p1 >= 0 && p1 < p2 && p2 <= 32)
	{
		int binary[60], temp, index = 0, size = 0;
		unsigned int decimal = 0;
		int swapar1[32], swapar2[32], swappedbi[60];
		for (int index = 0; index <60; index++)
			binary[index] = 0;
		for (int index = 0; index <60; index++)
			swappedbi[index] = 0;
		while (number != 0)
		{
			temp = number % 2;
			binary[index] = temp;
			number = number / 2;
			index++;
			size++;
		}
		if (p2 + n > size)
		{
			size = p2 + n;
		}

		int index1, index2;
		for (index = p1, index1 = 0; index1 < n; index++, index1++)
		{
			swapar1[index1] = binary[index];
		}


		for (index = p2, index1 = 0; index1 < n; index++, index1++)
		{
			swapar2[index1] = binary[index];
		}

		for (int index = p2, index2 = 0; index <= ((p2 - 1) + n); index++, index2++)
		{
			swappedbi[index] = swapar1[index2];
		}
		for (int index = p1, index2 = 0; index <= ((p1 - 1) + n); index++, index2++)
		{
			swappedbi[index] = swapar2[index2];
		}


		for (int index = 0; index < size; index++)
		{
			if (index >= p2 && index <= ((p2 - 1) + n))
				continue;
			else if (index <= ((p1 - 1) + n) && index >= p1)
				continue;
			else
				swappedbi[index] = binary[index];
		}


		if (p2 + n < 32)
		{
			for (index = 0; index <size; index++)
			{
				decimal = decimal + (swappedbi[index] * power(2, index));
			}
		}
		if (p2 + n >= 32)
		{
			for (index = 0; index <32; index++)
			{
				decimal = decimal + (swappedbi[index] * power(2, index));
			}
		}
		return decimal;
	}
	else
		return 0;



}
int power(int num, int mul)
{
	int num1 = num;
	if (mul == 0)
		return 1;
	if (mul > 0)
	{
		for (int index = 1; index < mul; index++)
			num *= num1;
		return num;
	}
}

