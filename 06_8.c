//	課題
#include <stdio.h>
void printStudent(unsigned char student);
unsigned char changeClass(unsigned char student, unsigned char cls);
int main(void)
{
	//student1 10101011
	unsigned char student1 = 0x6B;
	unsigned char student2 = 0xC6;


	// 学生1をクラスCへ変更
	student1 = changeClass(student1,2);
	//学生2をクラス1へ変更
	student2 = changeClass(student2,1);
	
	printStudent(student1);
	printStudent(student2);

	return 0;
}

void printStudent(unsigned char student)
{
	int class = 0;
	int number = 0;
	int gender = 0;

	class = (student >> 6) & 0x03;
	printf("クラス:%d", class);

	number = (student >> 1) & 0x1F;
	printf("出席番号:%2d", number);


	gender = student & 0x01;
	printf("性別:%d", gender);
}
unsigned char changeClass(unsigned char student, unsigned char cls)
{
	//student1の0110 1011と0011 1111(0x3F)を＆演算し00101011とする(マスク演算でクラスを00にし初期化した。)
	student = student & 0x3F;
	//変更後のclsが2(Cクラス)の場合→00000010
	//初期化したstudentの00101011と左に6つスライドしたcls　01000000をOR演算
	return student | (cls <<6);
	//計算結果『01101011』の上位2ビットが変更後のクラスとなる。　13行目のstudent1へ返す。
}

//これの為にこれをする