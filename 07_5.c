//	課題
#include <stdio.h>

int main(void)
{
	short num[] = { 234, 819, 18, -6492, 795, 20302, 2431, 9029, 0, -28009 };
	int i;
	int j;
	//	小さな値から順に並び替える
	//配列のデータが型に合わせることでコップの中身が溢れない。今回の場合は環境依存のint(2～4byte)でも対応できる。
	short min = 0;
	//初期値i=0、ループ条件:iより要素数－1が大きい時
	for (i = 0;i < (sizeof(num) / sizeof(num[0])) - 1;i++)
	{
		for (j = i+1;j < sizeof(num) / sizeof(num[0]);j++)
		{
			if (num[i] > num[j])
			{
				//入れたい場所=入れたい値;
				min = num[j];
				num[j] = num[i];
				num[i] = min;
			}
		}
	}

	//----------------------------------------
	//	順に表示する(ここは変更しない)
	for(i = 0; i < (sizeof(num) / sizeof(num[0])); i++)
	{
		printf("%d\n",num[i]);
	}

	return 0;
}