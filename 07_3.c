//	課題
#include <stdio.h>

int main(void)
{
	//このインデックスは全ての箱にゴミが入ったまま
	long kuku[9][9];
	long i;
	long j;
	
	// 九九の値の代入処理を記述
	for (i = 0; i < 9; i++)
	{
		for (j = 0; j < 9; j++)
		{
		//i*jだと0の段から始まりゴミが出力されてしまったのでiとjに1を足した
			kuku[i][j] = (i+1) * (j+1);
		
		}
	}
	

	/////////////////////////////////////
	// 九九の表示部（ここは変更しないこと）
	for (i = 0; i < 9; i++)
	{
		for(j = 0; j < 9; j++)
		{
			printf(" %2d", kuku[i][j]);
		}

		printf("\n");
	}

	return 0;
}