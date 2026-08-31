//	課題
#include <stdio.h>

//*全角スペースから半角に変更した
#define MAX_NUM			(10)	//	数字配列の要素数
//	正の数の配列
//*unsinged→unsigned
unsigned int number[MAX_NUM] =
{
	2398,
	1394,
	0x967,
	4987 / 2,
	4683,
	0x8436,
	7803 + 4789,
	0x978,
	0x00498,
	567 * 23,
//セミコロン追加
};

//----------------------------------------------------------------
//	number配列の最も大きな数字を取得する
//
//		戻り値	：number配列の最も大きな数字
//----------------------------------------------------------------
unsigned int getNumberOfMax(void)
{
	unsigned int max = 0;
	int count;

	//*,から;に変更
	for (count=0 ; count<MAX_NUM ; count++)
	{	
		if (max < number[count])
		//*波括弧追加
		{
			//*()を[]に変更
			max = number[count];
		}
	}

	return max;
}
//----------------------------------------------------------------
//	number配列の最も小さな数字を取得する
//
//		戻り値	：number配列の最も小さな数字
//----------------------------------------------------------------
unsigned int getNumberOfMin(void)
{
	unsigned int min = 0xFFFFFFFF;
	int count;

	for (count = 0; count < MAX_NUM; count++)
	{
		if (min > number[count])
		{
			min = number[count];
		}
	}

	return min;
//括弧追加
}
//----------------------------------------------------------------
//	main処理
//		number配列の最大値・最小値を表示する
//
//		戻り値	：0 正常終了
//----------------------------------------------------------------
int main(void)
{
	unsigned int maxValue;
	unsigned int minValue;
	
	maxValue = getNumberOfMax();
	//*スペルミスNunber→Number
	minValue = getNumberOfMin();

	printf("max:%d, min:%d", maxValue, minValue);

	return 0;
}

//関数名などスペルミスを起こしそうな場合はコピペを使うとよい
//エラーの行が問題なさそうなら上の行も確認してみる。エラーコードを検索して確認してみる。