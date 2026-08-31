//	‰Û‘è
#include <stdio.h>
long test1_1(long x, long y, long value);

int main(void)
{
	long input1 =5;
	long input2 = 30;
	long input3 = 1 ;
	long result = 0;

	result = test1_1(input1, input2,input3);

	printf("“ü—Í1: %d “ü—Í2: %d  “ü—Í3:%d “ü—Í o—Í: %d", input1, input2, input3, result);

	return 0;
}

long test1_1(long x, long y, long value)
{
	if( ( x >= 10 ) && ( y < 40 ) )
	{
		value = value + x + y;
	}

	if( ( value % 2 ) == 1 )
	{
		value = value * 2;
	}

	return value;
}