/*
OVERVIEW:
1)Write a function which takes a octal number as input and returns the hexadecimal number for 
  octalToHexadecimal().
E.g.: octalToHexadecimal(10) returns 8.

2)Write a function which takes a fractional octal number as input and returns the hexadecimal number for 
octalToHexadecimalFraction() until precision two
E.g.: octalToHexadecimal(6.01) returns 6.04

INPUTS: Single octal number num;

OUTPUT: hexadecimal value of the octal number num.

Discalimer:Return 0 for invalid cases.[Negetive Numbers]

There are no test cases for fraction method but it would be good if you complete that too.
*/
#include<stdlib.h>
#include<math.h>
int octalToHexadecimal(long int num)
{
	if (num > 0)
	{
		int decimal = 0, index = 0;
		int base = 8, hex = 0;

		while (num != 0)
		{
			decimal = decimal + ((num % 10)*(pow(base, index)));
			num = num / 10;
			index++;
		}


		while (decimal != 0)
		{
			hex = (hex * 10) + decimal % 16;
			decimal = decimal / 16;
		}

		
		hex = reverse(hex);
		//printf("%d",hex);
		return hex;
	}
	else
		return 23;
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

float octalToHexadecimalFraction(float num)

{
	int int_part = num, temp = 0, index = 1;
	float float_part = num - int_part;
	float dec_float = 0, decimal = 0;
	int_part = octalTodecimal(int_part);
	while (float_part != 0.0000)
	{
		temp = float_part * 10;
		dec_float = dec_float + (temp*pow(8, -(index)));
		float_part = temp - (float_part * 10);
		index++;

	}
	decimal = (float)int_part + dec_float;
	decimal -= 0.000004;
	
	float hexadecimal = decimaltohexadecimalFraction(decimal);
	return hexadecimal;

}
int octalTodecimal(long int num)
{


	int decimal = 0, index = 0;
	int base = 8, hex = 0;

	while (num != 0)
	{
		decimal = decimal + ((num % 10)*(pow(base, index)));
		num = num / 10;
		index++;
	}
	return decimal;

}
int decimaltohexadecimal(int decimal)
{
	int hex = 0;
	while (decimal != 0)
	{
		hex = (hex * 10) + decimal % 16;
		decimal = decimal / 16;
	}
	hex = reverse(hex);
	return hex;
}
float decimaltohexadecimalFraction(float decimal)
{
	int int_part = decimal;
	float float_part = decimal - int_part;
	int_part = decimaltohexadecimal(int_part);
	int temp = 0, hex_float = 0, divi = 1, count = 0;
	while (float_part != 0.000000)
	{
		temp = (float_part * 16);
		hex_float = (hex_float * 10) + temp;
		float_part = (float_part * 16) - temp;
		count++;

	}
	while (count>0)
	{
		divi *= 10;
		count--;
	}
	float hex_float_ = ((float)hex_float / (float)divi);
	float hex = (float)((float)(int_part)+hex_float_);
	return hex;
}