//	課題
#include <stdio.h>
//プロタイプ宣言で関数定義と同じもの＋；
void printBinary(unsigned char);
int main(void)
{
	unsigned char num = 0xDB;

	printf("変更前:");
	printBinary(num);
//落としたいビットのみ0にしてかける。
	num &= 0x4D;
	printf("変更後:");
	printBinary(num);

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