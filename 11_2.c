//	課題
#include <stdio.h>

//	getMaxMinArray関数を定義すること
int getMaxMinArray(unsigned long* Array, int size, unsigned long* max, unsigned long* min)
{
	int i;

	//NULLチェック_指定された場所が本当に存在するのかの確認
	if (Array == NULL || max == NULL || min == NULL)
	{
		return -1;
	}
	if (size <= 0)
	{
		return -2;
	}
	
	//間接参照演算子 この場合、Array[0]=7439なので始めはmax_valueが7439となる。
	*max = Array[0];
	*min = Array[0];
	//一番初めのループはArray[0]とi=1の比較なのでiは1で初期化する。
	//値の変更個が有ればつど矢を放つ感じ
	for (i = 1;i < size;i++)
	{
		if (Array[i] > *max)
		{
			*max = Array[i];
		}
		if (Array[i] < *min)
		{
			*min = Array[i];
		}

	}
	return 0;
}

int main(void)
{
	//	配列numは設定済み
	unsigned long num[10] = {7439, 84619, 203, 981266, 182, 749201, 2305829, 10528432, 9123, 494};
	unsigned long max_value;
	unsigned long min_value;
	int result;

	result = getMaxMinArray(num, 10,&max_value,&min_value);
	//	getMaxMinArray関数を呼び出す
	
	
	//	引数を正常に設定する場合と、引数のポインタをNULLにした場合で実行すること
	if (result == 0)
	{
		printf("最大値:%d　最小値:%d",max_value,min_value);
	}
	else
	{
		printf("最大・最小が取得できませんでした");
	}

	//	出力期待値に従い画面表示を行うこと


	return 0;
}