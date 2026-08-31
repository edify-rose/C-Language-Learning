//	‰Û‘è
#include <stdio.h>
short test1_2(char month, char day, short value);

int main(void)
{
	char month = 10;
	char day = 25;
	short value = 1500;
	short result = 0;

	result = test1_2(month, day, value);
	printf("“ü—Í1: %d “ü—Í2: %d “ü—Í3: %d o—Í: %d", month, day, value, result);

	return 0;
}

short test1_2(char month, char day, short value)
{
	if(( day == 10 ) || ( day == 20 ) || ( day == 30 ))
	{
		value = (short)( value * 0.9 );
	}
	else if(( day == 5 ) || ( day == 15 ) || ( day == 25 ))
	{
		if(( month != 5 ) && ( month != 11 ))
		{
			value = (short)( value * 0.95 );
		}
	}

	return value;
}