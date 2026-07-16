//	課題
#include <stdio.h>

int main(void)
{
	int i;
	int j;
	//初期値を1にし1の段からスタートできるようにした
	//繰り返しは『＜=』にすることで、回数分(9回)となる
	for (i = 1;i <= 9;i++)
	{
		for (j = 1;j <= 9;j++)
		{
	//文字間を広げたかった為%2dの後に半角を入れた
			printf("%2d ",i * j);
		}
		printf("\n");
	} 
	return 0;
}
