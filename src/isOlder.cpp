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
#include<stdlib.h>
int check_dateformat(char*,int*);
int check_year(int*);
int* convert(char*);


int isOlder(char *dob1, char *dob2) {

	int *dt1, *dt2,days,mons,yr;

	dt1 = (int*)malloc(3 * sizeof(int));
	dt2 = (int*)malloc(3 * sizeof(int));
	dt1 = convert(dob1);
	dt2 = convert(dob2);

	int result1=check_dateformat(dob1,dt1);
	int result2= check_dateformat(dob2,dt2);

	if (result1 == -1 || result2 == -1)
		return -1;
	else
	{
		
		if ((*(dt1 + 2)) > (*(dt2 + 2)))
			return 2;
		else if ((*(dt1 + 2)) < (*(dt2 + 2)))
			return 1;
		else if ((*(dt1 + 2)) = (*(dt2 + 2)))
		{
			if ((*(dt1 + 1)) > (*(dt2 + 1)))
				return 2;
			else if ((*(dt1 + 1)) < (*(dt2 + 1)))
				return 1;
			else if ((*(dt1 + 1)) = (*(dt2 + 1)))
			{

				if ((*(dt1 + 0)) > (*(dt2 + 0)))
					return 2;
				else if ((*(dt1 + 0)) < (*(dt2 + 0)))
					return 1;
				else if ((*(dt1 + 0)) = (*(dt2 + 0)))
				{
					return 0;
				}
			}
		}
	}
}


int check_year(int* year)
{
	if (*year % 4 == 0)
	{
		if (*year % 100 == 0)
		{
			if (*year % 400 == 0)
				return 1;
			else
				return 0;
		}
		else
			return 1;
	}
	else
		return 0;

}

int check_dateformat(char* d,int *dt)
{
	int leapyear = 0, i = 0;


	/*checking format DD-MM-YYYY*/
	if (*(d + 2) != '-' || *(d + 5) != '-')
		return -1;
	while ((*(d + i)) != '\0')
		i++;
	if (i > 10)
		return -1;
	
	/*checking months less than 12*/
	if ((*(dt + 1)) >12)
		return -1;


	/*checking for feb*/
	if ((*(dt + 1)) == 2)
	{
		leapyear = check_year(dt + 2);
		if (leapyear == 1 && ((*(dt + 0)) > 29))
			return -1;
		if (leapyear == 0 && (*(dt + 0)) > 28)
			return -1;
	}
	/*check for remining months*/
	if ((*(dt + 1)) == 1 || (*(dt + 1)) == 3 || (*(dt + 1)) == 5 || (*(dt + 1)) == 7 || (*(dt + 1)) == 8 || (*(dt + 1)) == 10 || (*(dt + 1)) == 12)
	{
		if (((*(dt + 0)) > 31))
			return -1;
	}
	if ((*(dt + 1)) == 4 || (*(dt + 1)) == 6 || (*(dt + 1)) == 9 || (*(dt + 1)) == 11)
	{
		if (((*(dt + 0)) > 30))
			return -1;
	}
	else
		return 1;
}


int* convert(char* d)
{
	int *dob;
	dob = (int*)malloc(3 * sizeof(int));
	*dob = (((*(d + 0)) - '0') * 10) + (((*(d + 1)) - '0') * 1);
	*(dob+1) = (((*(d + 3)) - '0') * 10) + (((*(d + 4)) - '0') * 1);
	*(dob + 2) = (((*(d + 6)) - '0') * 1000) + (((*(d + 7)) - '0') * 100) + (((*(d + 8)) - '0') * 10) + (((*(d + 9)) - '0') * 1);
	return dob;
}
