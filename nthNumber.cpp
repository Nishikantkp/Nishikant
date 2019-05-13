/*
Given a value n

1. return nth Fibonacci number for the function nthFibonacci(int)
	EX: 0 for n=1 and 1 for n=2


2. return nth prime number for the function nthPrime(int)
	EX: 2 for n=1 and 3 for n=2

INPUTS: single integer n

OUTPUTS: nth Fibonacci number for nthFibonacci() 
		 nth prime number for nthPrime()

ERROR CASES: return -1 for the error cases
*/

int nthFibonacci(int n)
{
	if (n>0)
	{
		int num1 = 0, num2 = 1, num3, count = 1;
		while (1)
		{
			if (count == n)
			{
				return num1;
			}
			num3 = num1 + num2;
			num1 = num2;
			num2 = num3;
			count++;
		}
	}
	else
		return -1;

}

int nthPrime(int num)
{
	if (num > 0)
	{
		int num1 = 2, count = 1, flag;
		if (num == 1)
			return num1;
		while (1)
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
				count++;
			if (count == num)
				return num1;
			num1++;
		}
	}
	return -1;
}