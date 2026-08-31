//	課題
#include <stdio.h>

//	円周率PIをマクロ定義せよ
//マクロ定義の命名規則は大文字で書く。アンダーバーでつなげる。
#define PI (3.141592)

//	円周を求めて戻り値とせよ
double getCircumference(double radius)
{
	return 2 * radius * PI;
}

//	円の面積を求めて戻り値とせよ
double getAreaCircle(double radius)
{

	return PI * radius * radius ;
}

int main(void)
{
	//	本関数は変更不要である

	double	r = 3.5;		//	半径
	double 	circumference;	//	円周
	double	area;			//	円の面積

	circumference	= getCircumference(r);
	area			= getAreaCircle(r);

	printf("円周：%lf 面積：%lf \n", circumference, area);

	return 0;
}

