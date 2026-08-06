//	課題
#include <stdio.h>
//プロタイプ宣言で関数定義と同じもの＋；
void printBinary(unsigned char);
int main(void)
{
	unsigned char num1= 160;
	char num2 = -100;
//算術シフトを使用した。右シフトの場合は型に注意
	num1 >>= 2;
	printf("num1: %d ",num1);
	printBinary(num1);
	printf("\n");
	num2 >>= 2;
	printf("num2: %d ", num2);
	printBinary(num2);

	return 0;
}

void printBinary(unsigned char num)
{
	int i;
	int binary = 0;

	for (i = 7;i >= 0;i--)
	{

		binary = num >> i & 1;

		printf("%d", binary);
	}
	return;
}
