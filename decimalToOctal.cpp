/*
OVERVIEW: 
1)Write a function which takes a decimal number as input and returns the octal number for decimalToOctal().
E.g.: decimalToOctal(10) returns 12.

2)Write a function which takes a fractional decimal number as input and returns the octal number for decimalToOctalFraction()
until precision two
E.g.: decimalToOctal(6.06) returns 6.03

INPUTS: Single decimal number num;

OUTPUT: Octal value of the Decimal Number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>

int decimalToOctal(int num)
{
	if (num > 0)
	{


		int octal = 0, temp, count = 0, mul = 1;
		int num1 = num;
		while (num1 % 8 == 0)
		{
			count++;
			num1 = num1 / 8;
		}

		while (num>0)
		{
			temp = num % 8;

			octal = (octal * 10) + temp;
			num = num / 8;
		}
		while (count)
		{
			mul *= 10;
			count--;
		}


		octal = reverse(octal);

		return (octal*mul);
	}
	else
		return 0;
}
int reverse(int num)
{
	int rev_no = 0, temp = 0;
	while (num != 0)
	{
		temp = num % 10;
		rev_no = (rev_no * 10) + temp;
		num = num / 10;

	}
	return rev_no;

}

float decimalToOctalFraction(float num)
{
	int int_part = num;
	float float_part = num - int_part;
	int temp;
	int octal_int = 0, octal_float = 0;
	int count = 0, divi = 1;
	octal_int = decimalToOctal(int_part);

	while (float_part != 0.000000)
	{
		temp = (float_part * 8);
		octal_float = (octal_float * 10) + temp;
		float_part = (float_part * 8) - temp;
		count++;

	}
	while (count>0)
	{
		divi *= 10;
		count--;
	}
	float octal_float_ = ((float)octal_float / (float)divi);
	float octal = (float)((float)(octal_int)+octal_float_);


	return octal;
}

