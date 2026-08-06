//	課題
#include <stdio.h>

int main(void)
{
	short point[10] = { 234, 819, 18, -6492, 795, 20302, 2431, 9029, 0, -28009 };
	int i;
	int max = point[0];

	
	//	最大の値を検索
	//if文の括弧内は最大値の更新をしていき一番最後に表示する
	for (i = 1;i < 10;i++)
	{
	//もし、maxよりループごとのpoint[i]が大きければ、point[i]をmaxとする。
		if (max < point[i])
		{
			max = point[i];
		}
	}
	printf("最大値:%d", max);
	//	最大の数字を表示
	return 0;
}
