//	課題
#include <stdio.h>

//	strcat_org関数を定義せよ
void strcat_org(char* str1, char*str2)
{
	int i;
	int j;

	for (i = 0;str1[i] != '\0';i++)
	{
	}
	for (j = 0;str2[j] != '\0';j++)
	{
	//str1[6]にstr2[0](W)を代入し、その後i++;でstr1[7]を作りそこにstr2[1](o)を代入これを繰り返す。

		str1[i] = str2[j];
		i++;
	}
	//j=6は最後のインクリメント先であってヌル文字はコピーされていない為、str1[i] = '\0';で文字の最後を認識させる必要がある。
	str1[i] = '\0';
	//str1[i] = '\0';これをつけないとメモリ崩壊がおこる。（本来のstr1の区切りを超えて文字を追加したため）
	//どちらにしてもメモリ崩壊は起こっているので、34行目の初期化時に要素数を追加後でも対応できる数字にしておくこと。
	return ;

}


int main(void)
{
	//	文字配列の定義をすること
	//		string1配列を定義 "Hello "で初期化
	//		string2配列を定義 "World!"で初期化
	char string1[20] = "Hello ";
	char string2[] = "World!";

	//	第1引数に第2引数の文字を結合
	strcat_org(string1, string2);

	//	結合された第1引数を表示。Hello World!が表示されればOK
	printf("%s\n", string1);

	return 0;
}