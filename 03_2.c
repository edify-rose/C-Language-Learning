//	課題
#include <stdio.h>

int main(void)
{

	short score = -1;
	if (score == 100)
	{
	//100点
		printf("大変よくできました\n");
	}
	//99～80点
	else if ((score <= 99) && (score >= 80))
	{
		printf("よくできました\n");
	}
	//79～50点
	else if ((score <= 79) && (score >= 50))
	{
		printf("次は頑張りましょう\n");
	}
	//49～1点
	else if ((score <= 49) && (score >= 1))
	{
		printf("もっと勉強しなさい\n");
	}
	//0点
	else if (score == 0) 
	{
		printf("がっかりです\n");
	}
	else
	{
		printf("不正です\n");
	}
	return 0;
}