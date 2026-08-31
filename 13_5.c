//	課題
#include <stdio.h>
#include <string.h>



int main(void)
{
#if 0

	//void* memcpy(void* restrict s1, const void* restrict s2, size_t n);
	int i;
	char s1[3] = { 'a','b','c' };
	char s2[3] = { 'd','e','f' };

	printf("\nコピー前のs1の値;");
	for (i = 0;i < 3;i++)
	{
		printf("%2x", s1[i]);
	}
	printf("\nコピー前のs2の値;");
	for (i = 0;i < 3;i++)
	{
		printf("%2x", s2[i]);
	}
	//s1コピー先オブジェクト、s2コピー元オブシェクト、コピーする文字数
	//s2 の先頭から 2バイト分（つまり s2[0] と s2[1] の d と e）を、s1 の場所にコピーします。
	memcpy(s1, s2, 2);

	printf("\nコピー後のs1の値;");
	for (i = 0;i < 3;i++)
	{
		printf("%2x", s1[i]);
	}
	printf("\nコピー後のs2の値;");
	for (i = 0;i < 3;i++)
	{
		printf("%2x", s2[i]);
	}

	return 0;
}
#endif

#if 0
//int memcmp(const void* s1, const void* s2, size_t n);
int ret;
char s1[] = { 'a','b','c' };
char s2[] = { 'a','d','e' };

ret = memcmp(s1, s2, 1);
if (ret == 0)
{
	printf("s1とs2の初めの1文字を比較すると、s1はs2と等しい。\n");
}
else if (ret > 0)
{
	printf("s1とs2の初めの1文字を比較すると、s1はs2より大きい。\n");
}
else if (ret < 0)
{
	printf("s1とs2の初めの1文字を比較すると、s1はs2より小さい。\n");
}
ret = memcmp(s1, s2, 2);
if (ret == 0)
{
	printf("s1とs2の初めの2文字を比較すると、s1はs2と等しい。\n");
}
else if (ret > 0)
{
	printf("s1とs2の初めの2文字を比較すると、s1はs2より大きい。\n");
}
else if (ret < 0)
{
	printf("s1とs2の初めの2文字を比較すると、s1はs2より小さい。\n");
}
}
#endif

#if 0
//void* memset(void* s, int c, size_t n);
int i;
char s[6];
//配列s(サイズ6)の先頭から6バイト分を、すべて文字 'a' で埋め尽くす。

memset(s, 'a', 6);
printf("\nsの値;");
for (i = 0;i < 6;i++)
{
	printf("%2x ", s[i]);
}
}
#endif

#if 1

//char* strcpy(char* restrict s1, const char* restrict s2);
//第2引数はコピーしたい物、第1引数はコピーしたい先。

char s1[16] = "abc";
char s2[16] = "def";

printf("コピー前のs1の値:%s\n", s1);
printf("コピー前のs2の値:%s\n", s2);

strcpy(s1, s2);

printf("コピー後のs1の値:%s\n", s1);
printf("コピー後のs2の値:%s\n", s2);
}
#endif

#if 0
//char* strcat(char* restrict s1, const char* restrict s2);
//第1引数の文字列の末尾に、第2引数の文字列を連結する関数です。
char s1[16] = "abc";
char s2[16] = "def";

printf("付加前のs1の値:%s\n", s1);
printf("付加前のs2の値:%s\n", s2);

strcat(s1, s2);
printf("付加後のs1の値:%s\n", s1);
printf("付加後のs2の値:%s\n", s2);
}
#endif

#if 0
//int strcmp(const char* s1, const char* s2);
//2つの文字列を先頭から1文字ずつ辞書順（文字コードの大小）で比較する関数です。
//1文字目：s1[0] の 'a' と s2[0] の 'a' は一致します。
//2文字目：s1[1] の 'b'（文字コード 98）と s2[1] の 'd'（文字コード 100）を比較します。
int ret;
char s1[] = "abc";
char s2[] = "ade";

ret = strcmp(s1, s2);
if (ret == 0)
{
	printf("s1とs2を比較すると、s1はs2と等しい。\n");
}
else if (ret > 0)
{
	printf("s1とs2を比較すると、s1はs2より大きい。\n");
}
else if (ret < 0)
{
	printf("s1とs2を比較すると、s1はs2より小さい。\n");
}
}
#endif

#if 0
//size_t strlen(const char* s);
	char s[] = "abcdef";
	int len;
	len = strlen(s);
	printf("%sの長さは%dです。\n", s, len);
}
#endif
