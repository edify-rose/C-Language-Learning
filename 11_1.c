//	課題
#include <stdio.h>

//	addArray関数を定義すること
//ポインタ変数がnumの先頭番地を受け取る
void addArray(short* Array, int size)
{
	int i;
	for (i = 0;i < size;i++)
	{
	//Arrayからみて何番目
		Array[i]+= 100;
		
		//*(Array+i)+=100;　何個横にずれたか
		
		//*Array+=100;
		//Array++;  右に一個ずつずれていく

	}
	return;
}


int main(void)
{
	short num[] = {10,20,30,40,50};
	int size = sizeof(num) / sizeof(num[0]);
	int i;

	addArray(num, size);
	//	addArray関数を呼び出すこと
	
	for (i = 0;i < size;i++)
	{
		printf("num[%d]=%d\n", i, num[i]);
	}
	//	num配列の値を順に画面出力すること


	return 0;
}