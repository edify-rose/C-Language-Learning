//	課題
#include <stdio.h>

//	getYear関数を定義すること

void getYear(long*pYear);
int main(void)
{
	long year = 0;

	//getYear関数の呼び出し
	getYear(&year);
	//西暦を表示すること
	printf("西暦:%d", year);
	return ;
}
void getYear(long*pYear)
{
	*pYear = 2019;
	//pYear=17行目の引数の事で9行目のyearの番地が入っている
	//
	return;
}

//pYearにはyearの箱のアドレスが入っていて*pYearになると間接参照演算子によりlong year = 0;(9行目)のyearを指す