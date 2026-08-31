//	課題
#include <stdio.h>

//	reverseString関数を定義せよ
void reverseString(char* str)
{
	int i;
	int j;
	char temp;
	
	for (i = 0;str[i] != '\0';i++)
	{
	}
	//インクリメント先はi=12のヌル文字なのでi--;で「！」にする。
	i--;

	//i=11とj=0の比較からスタート
	for (j = 0;i > j;j++)
	{
		//スワップ　文字の入れ替え
		temp = str[i];
		str[i] = str[j];
		str[j] = temp;

	//比較毎にiをディクリメントする。
		i--;
	}
	return;
}


int main(void)
{
	char string[] = "Hello World!";

	//	文字列を前後反転
	reverseString(string);

	//	"!dlroW olleH"が表示されればOK
	printf("%s\n", string);

	return 0;
}