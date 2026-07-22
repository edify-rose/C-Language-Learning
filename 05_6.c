//	‰Û‘è
#include <stdio.h>

void printSquare(long len);
int main(void)
{
	long len = 5;
	printSquare(len);
	return;
}
void printSquare(long len)
{
	int i;
	int j;

	for (i = 0;i < len;i++)
	{
		for (j = 0;j < len;j++)
		{
			printf("$");
		}
		printf("\n");
	}
	return 0;
}