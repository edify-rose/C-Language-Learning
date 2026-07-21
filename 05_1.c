//	課題
#include <stdio.h>

//unsigned char型のデータをもらってlong型のデータで返すと宣言
long getTriangleArea(unsigned short base, unsigned short height)
{
//●三角形の面積の計算してmainAreaへ送る
	return(base * height / 2); //ここで出るのが戻り値
}


int main(void)
{
//仮の箱を3つ準備(データ送信用2個・受信用1個)
//▲getTriangleArea関数の引数へデータを送る為、データ型はunsigned short型に合わせる
	unsigned short mainBase = 10;
	unsigned short mainHight = 20;
//関数処理後のデータを受け取る為戻り値のデータ型に合わせる
	long mainArea = 0;

//関数呼び出し
//●getTriangleAreaの関数を呼び出す。戻り値を受け取る。
mainArea = getTriangleArea(mainBase, mainHight);

printf("底辺:%d　高さ:%d　面積:%d", mainBase, mainHight, mainArea);
return 0;
}

