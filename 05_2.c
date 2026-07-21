//	課題
#include <stdio.h>
// longr型のデータをもらってlong型のデータで返すと宣言
//引数の箱を用意しているイメージ(呼び出しされるまでは空箱)
long getSummation(long start, long end)
{
	int i;
//totalの値は戻り値へ戻す為戻り値の型に合わせる必要がある
	long total = 0;

	for (i = start; i <= end;i++)
	{
		total += i;
	}
	return total;
}
int main(void)
{
//仮の箱を3つ準備(データ送信用2個・受信用1個)
//getSummation関数の引数へデータを送る為、データ型はlong型に合わせる
	long mainStart = 15;
	long mainEnd = 100;
//関数処理後のデータを受け取る為戻り値のデータ型に合わせる
	long mainTotal = 0;

//getSummation関数を呼び出す。mainTotalの戻り値を受け取る
//28行目→5行目→関数処理終了後戻り値を受け取るためにまた戻ってくる。
	mainTotal = getSummation(mainStart, mainEnd );
	printf("開始:%d 終了:%d 総和:%d", mainStart, mainEnd, mainTotal);

	return 0;
}