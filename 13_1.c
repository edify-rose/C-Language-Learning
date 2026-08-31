//	課題
#include <stdio.h>

//	strlen_org関数を定義すること
int strlen_org(char* str)
{
	int i;
	int count=0;

	//ヌル文字にならないならループ(ヌル文字になるまで)
	for (i= 0;str[i] != '\0';i++)
	{
		count++;
	}
	return count;
}

int main(void)
{
	//	次の文字列をstring配列に設定しサイズが正しく表示されることを確認すること
	//"Hello World!"		12文字
	//	"Fuzisan"			7文字
	//	""					0文字
	//char string[] = "Hello World!";
	//char string[] = "Fuzisan";
	char string[] = "";



	//	文字の長さ取得と表示
	printf("len:%d\n", strlen_org(string));

	return 0;
}