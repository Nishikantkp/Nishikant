/*
OVERVIEW: 	Given date of births of two persons as inputs, return 1 if person one is elder,
2 if person two is elder, 0 if both are of same age.
Example: isOlder("24-07-2000", "25-07-2000") should return 1 as person one
is elder than person two.

INPUTS: 	DOBs of two persons as parameters in the format "DD-MM-YYYY".

OUTPUT: 	1 if person one is elder, 2 if person two is elder, 0 if both are of same age.

ERROR CASES: Return -1 if any DOB is invalid.

NOTES: 		Don't use any built-in C functions for comparisions. You are free to write any helper functions.
*/
int isOlder(char *dob1, char *dob2) {
	{
		int day1, day2, mon1, mon2, yr1, yr2;
		int day_limit1 = 32, day_limit2 = 32;
		sscanf(dob1, "%d-%d-%d", &day1, &mon1, &yr1);
		sscanf(dob2, "%d-%d-%d", &day2, &mon2, &yr2);
		int check1 = isLeapyear(yr1);
		int check2 = isLeapyear(yr2);
		if (check1 == 0 && mon1 == 2)
			day_limit1 = 29;
		if (check2 == 0 && mon2 == 2)
			day_limit2 == 29;


		if (mon1 < 13 && mon2 <13 && mon1 > 0 && mon2 >0 && day1 < day_limit1 && day2 < day_limit2)
		{
			if (yr1 < yr2)
				return 1;
			else if (yr1 >yr2)
				return 2;
			if (yr1 == yr2 && mon1 < mon2)
				return 1;
			else if (yr1 == yr2 && mon1 > mon2)
				return 2;
			else if (yr1 == yr2 && mon1 == mon2 && day1 < day2)
				return 1;
			else if (yr1 == yr2 && mon1 == mon2 && day1 > day2)
				return 2;
			else
				return 0;
		}
		else
			return -1;
	}

}
int isLeapyear(int year)
{
	if (((year % 4 == 0) && (year % 100 != 0)) || (year % 400 == 0))
		return 1;
	else
		return 0;
}