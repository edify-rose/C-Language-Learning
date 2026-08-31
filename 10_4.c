//	課題
#include <stdio.h>

//	define定義を行うこと
#define D_APPLE_ID (1)
#define D_ORANGE_ID (2)
#define D_BANANA_ID (3)


int getFruitPrice(short fruitID, long* price);
//	getFruitPrice関数を定義すること

int main(void)
{
	//short fruitID = 4;
	short fruitID = D_ORANGE_ID;
	//short fruitID = D_BANANA_ID;
	long price=0;
	int result;


	result = getFruitPrice(fruitID, &price);
	//	getFruitPrice関数の呼び出し
	
	//	fruitsIDにリンゴ、みかん、バナナ、その他を与え金額を取得
	if (result== 0)
	{
		//出力期待値を画面に表示
		printf("%dのフルーツが%d円ならば買います。", fruitID , price);
	}
	else
	{
		printf("%dのフルーツながないのは残念です。", fruitID);
	}
	return 0;
}
int getFruitPrice(short fruitID, long* price)
{
	switch (fruitID)
	{
		case D_APPLE_ID:
			*price = 150;
			break;
		case D_ORANGE_ID:
			*price = 100;
			break;
		case D_BANANA_ID:
			*price = 80;
			break;
		default:
			return -1;
			break;
	}
	return 0;
}