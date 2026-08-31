//	課題
#include <stdio.h>

// テスト結果管理構造体
typedef struct
{
	int studentID;		// 学生番号
	int	language;		// 国語
	int	mathematics;	// 数学
	int	science;		// 理科
	int	society;		// 社会
} S_Subject;

int main(void)
{
	int i;
	int average;

	// 学生毎のテスト結果
	//S_Subjectが5段(i=0～4)あるということ。
	S_Subject student[5] =
	{
		//学生ID　...
		{1, 40, 89, 65, 55},	// 学生1
		{2, 82, 32, 45, 60},	// 学生2
		{3, 30, 52, 47, 72},	// 学生3
		{4, 70, 79, 68, 65},	// 学生4
		{5, 92, 42, 82, 31},	// 学生5
	};

	for (i = 0;i < 5;i++)
	{
		//	学生毎の平均点を順に表示せよ
		average = (student[i].language + student[i].mathematics + student[i].science + student[i].society) / 4;

		printf("学生ID:%d 平均点:%d\n", student[i].studentID, average);
	}
	return 0;
}