//	‰Û‘è
#include <stdio.h>
void printTriangle(long len);
int main(void)
{
	long len = 4;

	printTriangle(len);

	return 0;
}
void printTriangle(long len)
{
	int i;
	int j;

	for (i = 0; i < len;i++)
	{
		for (j = 0;j < (len - i - 1);j++)
		{
			printf(" ");
		}
		for (j =0;j<=i ;j++)
		{
			printf("#");
		}
		printf("\n");
	}
	return ;
}