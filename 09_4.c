//	課題
#include <stdio.h>

//台形の面積を求めるtrapezoidの関数マクロをここに定義せよ
#define trapezoid(upper,bottom,height) (((upper)+(bottom))*(height)/2)

int main(void)
{
    double area;        //  面積

    //  台形の面積を取得
    area = trapezoid(5.2 + 2, 8.1 - 2.5, 4.0 + 2.0 );
    printf("台形の面積：%lf\n", area);
    return 0;
}