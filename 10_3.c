//	課題
#include <stdio.h>

//	getTaxPrice関数を定義すること
int getTaxPrice(long price, long* taxprice);
int main(void)
{
	long taxprice = 0;
	int result;

	//	getTaxPrice関数の呼び出し
	//result = getTaxPrice(20000, &taxprice);
	result = getTaxPrice(0, &taxprice);
	//result = getTaxPrice(-100, &taxprice);
    //引数priceに 20000円 , 0円 , -100円 を入れてそれぞれ出力期待値を表示すること
	
	if (result == 0)
	{
		printf("税込み:%d円なら購入します。", taxprice);
	}
	else 
	{
		printf("税抜き価格がおかしかったですかね。");
	}
	return 0;
}
int getTaxPrice(long price, long* taxprice)
{
	if (price <= 0) 
	{
		return -1;
	}
	*taxprice =(long)(price*1.1);
	/*明示的なキャストを行った。
	taxpriceのデータ型はロング型、priceのデータ型ロングだが、1.1(浮動小数点)とかけている為double型となる
	その場合、double型をlong型に代入する事になる。それはオーバーフローになる為、明示的なキャストを行い(price*1.1)をlong型とした。*/
	return 0;
}