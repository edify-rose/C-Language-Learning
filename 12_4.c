//	課題
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	unsigned long* pData = NULL;	//	確保したヒープメモリの先頭番地を管理させる

	//	mallocでunsigned long型のメモリを1024 * 1024個分確保すること。pDataに番地を設定すること。
	pData = (unsigned long*)malloc(sizeof(unsigned long) * 1024 * 1024);

	if (pData == NULL)
	{
		return -1;
	}
	//	確保したメモリ配列[1024 * 1024]個に順番に0、1、2・・・と連番を代入すること
	int i;
	for (i = 0;i < 1024 * 1024;i++)
	{
		pData[i] = i;
	}

	//	配列インデックスで指定した場所にインデックス番号の数値が入っていることを確認する
	//	↓ここは変更しないこと↓
	printf("pData[50000] : %d\n", pData[50000]);
	printf("pData[100000] : %d\n", pData[100000]);
	//	↑ここは変更しないこと↑


	//	確保したヒープメモリの解放を行うこと
	free(pData);
	pData = NULL;

	return 0;
}