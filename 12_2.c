//	課題
#include <stdio.h>

//	altGreeting関数を定義せよ
void altGreeting(void)
{
	//static変数を使って、何回目の呼び出しかを関数の中に記憶させる
	//数値が0と1の行き来をする(フラグ)だけなのでオーバーフローの心配がない。
	
	static int i=1;
	
	if (i == 0)
	{
		printf("こんばんは\n");
		i++;
		//i=1;
	}
	else
	{
		printf("おはよう\n");
		i--;
		//i=0;
	}
	return ;
}

int main(void)
{
	//-----------------------------------------
	//	本関数は修正しない
	//-----------------------------------------

	int i;

	//	3日分の挨拶を行う
	for (i = 0; i < (3 * 2); i++)
	{
		altGreeting();
	}

	return 0;
}