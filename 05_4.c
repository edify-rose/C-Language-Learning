//	課題
#include <stdio.h>
//プロトタイプ宣言セミコロン忘れないように！

void hello(short year);
int main(void)
{
	hello(2019);
	return 0;
}

void hello(short year)
{
	printf("Hello world %d", year);
	return ;
}

//ここからコメントアウト
/*
#include <stdio.h>
//short型のデータをもらう。戻り値無し
void hello(short year)
{
	printf("Hello world %d", year);
	return;
}

int main(void)
{
	//関数呼び出し。括弧内の数値を直接4行目のyearにわたしている。
	//変数の初期値を定義している場合は箱に入っているイメージ
	//直接数値を渡している場合は箱がないイメージ
	//関数を呼び出す場合変数(引数)を使っている場合、中のものだけ引数に渡している
	//直接数値を渡している場合箱は存在しない(直置きのイメージ)
	hello(2019);

	return 0;
}

    //変数と引数は違う(引数は必要な材料を準備しておくスペース、変数は具体的な物の名前)
	// 引数というお皿に乗っている変数というイメージ
　　//ミキサーのイメージ関数名がミキサーその中に入れる材料が引数、その材料として用意されている物が変数

*/