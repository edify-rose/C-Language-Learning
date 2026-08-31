//	課題
#include <stdio.h>

//	関数ポインタをtypedefで型定義すること
typedef void(*FP_FUNC)(void);

//	outputHello関数は定義済み
void outputHello(void)
{
	printf("Hello\n");
}

int main(void)
{
	//　関数ポインタ変数を定義すること　変数定義と同じ関数を受け取る為の変数を作る。
	// 関数を受け取れる型は5行目で定義した。戻り値引数ともにvoid型で関数ポインタ型名はFP_FUNC。変数名はprocces1  "=の後は番地番号nullは0番地"
	FP_FUNC process1 = NULL;

	//	関数ポインタへ関数をセットすること
	//outputHello関数の番地番号が入った　8行目の番地が入った。
	process1 = outputHello;

	//	関数ポインタを利用してoutputHello関数を呼び出すこと　8行目に行く
	process1();

	return 0;
}

//理解度確認テスト問14を参考にした。
//こことは別の場所で関数を定義した場合に、その番地だけが分かっていれば呼び出すことが出来る。