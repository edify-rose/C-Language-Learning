//	課題
#include <stdio.h>

int main(void)
{
	long num = 15;
	int a = 0;

	while (a * a < num)
	{
		a++;
	}
	printf("目標値:%d 二乗値: %d 二乗後の値%d", num, a, a * a);
	return 0;
}