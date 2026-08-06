//	課題
#include <stdio.h>
void printStudent(unsigned char student);
int main(void)
{
	unsigned char student1 = 0x6B;
	unsigned char student2 = 0xC6;

	printStudent(student2);

	return 0;
}
void printStudent(unsigned char student)
{
	int class = 0;
	int number = 0;
	int gender = 0;
	//取り出したい部分を1にする　00000011が0x03
	//先にシフトを行うことで算術シフトでも対応できるようになっている。
	class = (student >> 6) & 0x03;
	printf("クラス:%d", class); 

	number = (student >> 1) & 0x1F;
	printf("出席番号:%2d", number);
	

	gender = student & 0x01;
	printf("性別:%d",gender);
	return 0;
}

