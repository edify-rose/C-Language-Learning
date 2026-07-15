//	課題
#include <stdio.h>

int main(void)
{
	short year = 2100;
//『ただし例外』の時入れ子構造を使う
//else等が何処と対応するかよく確認すること

	if (year % 4 == 0)
	{
		if ((year % 100 == 0) && (year % 400 != 0))
		{
			printf("西暦%d　:平年", year);
		}
	
		else
		{
			printf("西暦%d :うるう年", year);
		}
	}
	else
	{
		printf("西暦%d:平年", year);
	}

	/*
	if (year % 400 == 0)
	{
		printf("西暦%d年 :うるう年" ,year);
	}
	else if (year % 100 == 0)
	{
		printf("西暦%d　:平年", year);
	}
	else if (year % 4==0)
	{
		printf("西暦%d　:うるう年", year);
	}
	else
	{
		printf("西暦%d　:平年", year);
	}
	*/
		return 0;
}
//条件にはまった順で処理が終るため、例外から条件を並べなければいけない

//100で割り切れて400で割り切れない年…
//→400で割り切れる物を真とし、偽の場合（次の処理）にそれを100で割り切れる物を平年とする
//その後4で割り切れるものをうるう年とし、最後にその他は平年とする。

