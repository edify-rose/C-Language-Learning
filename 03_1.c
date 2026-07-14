//	課題
#include <stdio.h>

int main(void)
{

	// **********if文の場合**********

	char student = 2;

	if (student == 0)
	{
		printf("出席番号:0 氏名:出席番号無効\n");
	}
	else if (student == 1)
	{
		printf("出席番号:1 氏名:山田太郎\n");
	}
	else if (student == 2)
	{
		printf("出席番号:2 氏名:高橋花子\n");
	}
	else
	{
		printf("そんな人はいません\n");
	}

	// ********switch文の場合********

	switch (student)
	{
		case(0):
			printf("出席番号:0 氏名:出席番号無効\n");
			break;
		case(1):
			printf("出席番号:1 氏名:山田太郎\n");
			break;
		case(2):
			printf("出席番号:2 氏名:高橋花子\n");
			break;
		default:
			printf("出席番号:%d人はいません\n",student);
			break;
	}
	return 0;
}

			