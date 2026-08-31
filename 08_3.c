//	課題
#include <stdio.h>
typedef struct
{
    char name[32];
    short age;
    double height;
    double weight;
}S_Human;

int main(void)
{
    int i;
    S_Human people[] =
    {
        //氏名　//年齢　//身長　//体重
        { "Jack",     34, 168.5, 56.4},
        { "George",   43, 183.6, 98.8},
        { "Leonardo", 30, 179.2, 68.5},
        { "Gabriel",   7, 120.6, 24.7},
        { "Henry",    18, 175.6, 63.5},
    };

    printf("抽出対象①\n");
    for (i = 0;i < 5;i++)
    {
        if ((people[i].height >= 170) && (people[i].weight >= 60))
        {
            printf("%s\n", people[i].name);
        }
    }
    printf("\n\n\n");
    printf("抽出対象②\n");
    for (i = 0;i < 5;i++)
    {
        if ((people[i].age < 30) || (people[i].height <= 170))
        {
            printf("%s\n", people[i].name);
        }
    }
    return 0;
}