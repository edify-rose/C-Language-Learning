//	課題
#include <stdio.h>

void getDay(long* pYear, char* pMonth, short* pDay);
int main(void)
{
	long year = 0;
	char month = 0;
	short day = 0;

	//	getDay関数を呼び出す
	getDay(&year, &month, &day);
	//	西暦の年月日を表示すること
	printf("西暦:%d年%d月%d日", year, month, day);

	return;
}
//	getDay関数を定義すること
void getDay(long*pYear, char*pMonth, short*pDay)
{
	* pYear = 2019;
	* pMonth = 4;
	* pDay = 8;
	
	return ;
}

//10-1との違いは引数が増え全てデータ型が違う。→関数定義では参照先のデータ型に合わせる
