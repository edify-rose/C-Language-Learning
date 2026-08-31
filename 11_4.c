//	課題
#include <stdio.h>

//	構造体S_Personをtypedefで定義すること
typedef struct
{
	char name[32];
	short age;
	double height;
	double weight;
}S_Person;

int printPerson(S_Person*personInfo)
//	printPerson関数を定義すること
{
	if (personInfo == NULL)
	{
		return -1;
	}

	printf("氏名:%s\n年齢:%d歳\n身長:%lfcm\n体重:%lfkg", personInfo->name, personInfo->age, personInfo->height, personInfo->weight);

	return 0;
}

int main(void)
{

	//	構造体変数personを定義し初期化を行うこと
	S_Person person = { "山田太郎",34,185.3,68.2 };

	//	printPerson関数を呼び出すこと
	printPerson(&person);

	//	personのポインタを渡す場合とNULLポインタを渡す場合で実行すること
	
	return 0;
}