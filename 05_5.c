//	‰Û‘è
#include <stdio.h>
long getMaxNum(long num1, long num2, long num3);
int main(void)
{
	long mainNum1 = 10;
	long mainNum2 = 15;
	long mainNum3 = 40;
	long mainMax = 0;

	mainMax = getMaxNum(mainNum1, mainNum2, mainNum3);
	printf("“ü—Í:%ldA%ldA%ld Å‘å:%ld", mainNum1, mainNum2, mainNum3,mainMax);
}
long getMaxNum(long num1, long num2, long num3)
{

	long max = num1;

	if (max < num2)
	{
		max = num2;
	}
	if(max < num3)
	{
		max = num3;
	}
	return max;
}