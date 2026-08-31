//	課題
#include <stdio.h>

//	upper関数を定義すること
void upper(char* str)
{
	int i;
	for(i = 0;str[i]!='\0';i++)
	{
		if (str[i] >= 'a' && str[i] <= 'z')
		{
			str[i] -= 0x20; //小文字aと大文字Aの差が20
			//str[i]-='a'-'A'; //上と同じ意味
		}
	}
	//returnは全文字の変換が終了したという合図
	return ;
}


int main(void)
{
	char string[] = "Hello World!";

	upper(string);

	//	"HELLO WORLD!"が表示されればOK
	printf("%s\n", string);

	return 0;
}